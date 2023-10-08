#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <utility>
#include "test_runner.h"

using namespace std;

class ReadingManager {
public:

  ReadingManager()
      : users2pages(MAX_USER_COUNT_ + 1, 0),
        pages2users(1001, 0), 
        pages2rating(1001, 0) {}

  void Read(int user_id, int page_count) {
    int old_page_count = this->users2pages[user_id];
    if (old_page_count) {
        --this->pages2users[old_page_count];
    } else {
        ++this->user_count;
    }

    this->users2pages[user_id] = page_count;
    ++this->pages2users[page_count];
    getRating();
  }

  double Cheer(int user_id) {
    int page_count = this->users2pages[user_id];
    if ( page_count == 0 ) {
        return 0.0;
    }

    if ( this->user_count == 1 ) {
        return 1.0;
    }

    double low_users = this->pages2rating[page_count];
    return low_users / (this->user_count - 1);
  }

private:
  static const int MAX_USER_COUNT_ = 100000;

  vector<int> users2pages;
  vector<int> pages2users;
  vector<double> pages2rating;
  int user_count = 0;

  void getRating() {
    double low_users = 0.0;
    for (int i = 0; i <= 1000 ; i++) {
        this->pages2rating[i] = low_users;
        low_users += this->pages2users[i];
    }
  }
};

void TestReadPage() {
	{// add user
		ReadingManager manager;
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		manager.Read(1, 1);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
	}
	{// add user but cheer not existed
		ReadingManager manager;
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		manager.Read(1, 1);
		ASSERT_EQUAL(manager.Cheer(2), 0.0);
	}
	{// read twice
		ReadingManager manager;
		manager.Read(1, 1);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
		manager.Read(1, 2);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
	}
	{// better than third
		ReadingManager manager;
		manager.Read(1, 1);
		manager.Read(2, 2);
		manager.Read(3, 3);
		ASSERT_EQUAL(manager.Cheer(2), 0.5);
		manager.Read(4, 4);
		ASSERT_EQUAL(manager.Cheer(2), 1.0 / 3.0);
	}
	{// better than 2 third
		ReadingManager manager;
		manager.Read(1, 1);
		manager.Read(2, 2);
		manager.Read(3, 3);
		ASSERT_EQUAL(manager.Cheer(2), 0.5);
		manager.Read(4, 4);
		ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
	}
	{// read zero
		ReadingManager manager;
		manager.Read(1, 0);
		manager.Read(2, 0);
		manager.Read(3, 1);
		manager.Read(4, 2);
		ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
	}
	{// all read the same
		ReadingManager manager;
		manager.Read(1, 5);
		manager.Read(2, 5);
		manager.Read(3, 5);
		manager.Read(4, 5);
		ASSERT_EQUAL(manager.Cheer(3), 0.0);
	}
	{// reverse order
		ReadingManager manager;
		manager.Read(4, 5);
		manager.Read(3, 4);
		manager.Read(2, 3);
		manager.Read(1, 2);
		ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
	}
	{// two users read two times
		ReadingManager manager;
		manager.Read(4, 5);
		manager.Read(3, 4);
		manager.Read(4, 6);
		manager.Read(3, 5);
		ASSERT_EQUAL(manager.Cheer(4), 1.0);
		ASSERT_EQUAL(manager.Cheer(3), 0.0);
		manager.Read(10, 2);
		ASSERT_EQUAL(manager.Cheer(3), 0.5);
		ASSERT_EQUAL(manager.Cheer(4), 1.0);
	}
	{// only one user
		ReadingManager manager;
		manager.Read(4, 5);
		ASSERT_EQUAL(manager.Cheer(4), 1.0);
		manager.Read(4, 6);
		ASSERT_EQUAL(manager.Cheer(4), 1.0);
		manager.Read(4, 100);
		ASSERT_EQUAL(manager.Cheer(4), 1.0);
		ASSERT_EQUAL(manager.Cheer(3), 0.0);
		ASSERT_EQUAL(manager.Cheer(5), 0.0);
	}
	{// ten users
		ReadingManager manager;
		manager.Read(1, 1);
		manager.Read(2, 2);
		manager.Read(3, 3);
		manager.Read(4, 4);
		manager.Read(5, 5);
		manager.Read(6, 6);
		manager.Read(7, 7);
		manager.Read(8, 8);
		manager.Read(9, 9);
		manager.Read(100, 10);
		manager.Read(111, 11);
		
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		ASSERT_EQUAL(manager.Cheer(2), 0.1);
		ASSERT_EQUAL(manager.Cheer(3), 0.2);
		ASSERT_EQUAL(manager.Cheer(4), 0.3);
		ASSERT_EQUAL(manager.Cheer(5), 0.4);
		ASSERT_EQUAL(manager.Cheer(6), 0.5);
		ASSERT_EQUAL(manager.Cheer(7), 0.6);
		ASSERT_EQUAL(manager.Cheer(8), 0.7);
		ASSERT_EQUAL(manager.Cheer(9), 0.8);
		ASSERT_EQUAL(manager.Cheer(100), 0.9);
		ASSERT_EQUAL(manager.Cheer(111), 1.0);
		ASSERT_EQUAL(manager.Cheer(12), 0.0);
	}
	{// cheer twice
		ReadingManager manager;
		
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		manager.Read(1, 1);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
		
		ASSERT_EQUAL(manager.Cheer(2), 0);
	}
	{// max ID
		const int MAX_USER_COUNT = 100000;
		ReadingManager manager;		
		ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
		manager.Read(MAX_USER_COUNT, 1);
		ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
	}
	{// max page
		ReadingManager manager;		
		ASSERT_EQUAL(manager.Cheer(1), 0.0);
		manager.Read(1, 1000);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
	}
	{// max ID and max page
		const int MAX_USER_COUNT = 100000;
		ReadingManager manager;		
		ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
		manager.Read(MAX_USER_COUNT, 1000);
		ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
	}
	{// zero ID
		ReadingManager manager;		
		ASSERT_EQUAL(manager.Cheer(0), 0.0);
		manager.Read(0, 1000);
		ASSERT_EQUAL(manager.Cheer(0), 1.0);
	}
	{// from coursera (https://www.coursera.org/learn/c-plus-plus-red/programming/e72ST/eliektronnaia-knigha/discussions/threads/hLK3cT0AEemHtRKqiMW_lA)
		ReadingManager manager;		
		manager.Read(1, 1);
		manager.Read(1, 3);
		manager.Read(2, 2);
		ASSERT_EQUAL(manager.Cheer(1), 1.0);
		ASSERT_EQUAL(manager.Cheer(2), 0.0);
	}
    {
        ReadingManager manager;
        manager.Read(1, 1000);
        manager.Read(2, 999);
        ASSERT_EQUAL(manager.Cheer(1), 1);
    }
}


int main() {
  TestReadPage();

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}

// 12
// CHEER 5 // 0
// READ 1 10
// CHEER 1 // 1
// READ 2 5
// READ 3 7
// CHEER 2 // 0
// CHEER 3 // 0.5
// READ 3 10
// CHEER 3 // 0.5
// READ 3 11
// CHEER 3 // 1
// CHEER 1 // 0.5
