#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include "test_runner.h"

using namespace std;

// BOOK time hotel_name client_id room_count — 
//       забронировать клиентом client_id room_count номеров в отеле hotel_name в момент времени time. 
//       Время измеряется в секундах, отсчитываемых от некоторого момента.
//
// CLIENTS hotel_name — 
//       вывести количество различных клиентов, бронировавших номера в отеле hotel_name за последние сутки. 
//       Более формально интересующий диапазон времени описывается следующим образом: 
//       пусть current_time — время последнего события BOOK, тогда в данном запросе нужно учесть все события 
//       с current_time − 86400 < time ⩽ current_time, где 86400 — количество секунд в сутках. 
//       Обратите внимание, что последнее бронирование должно учитываться, а бронирование, 
//       случившееся ровно за сутки до него, учитываться не должно.
//
// ROOMS hotel_name — 
//       вывести количество номеров, забронированных за последние сутки в отеле hotel_name.
//
// time — целое число в диапазоне от −10^18 до 10^18 и не убывает от события к событию. (long long int)
// hotel_name — строка из латинских букв и цифр, имеющая длину не более 12 символов. (string)
// client_id — натуральное число, не превосходящее 10^9. (int)
// room_count — целое положительное число, не превосходящее 1000. (short int)

// 11
// CLIENTS Marriott           // 0
// ROOMS Marriott             // 0
// BOOK 10 FourSeasons 1 2
// BOOK 10 Marriott 1 1
// BOOK 86409 FourSeasons 2 1
// CLIENTS FourSeasons        // 2
// ROOMS FourSeasons          // 3
// CLIENTS Marriott           // 1
// BOOK 86410 Marriott 2 10
// ROOMS FourSeasons          // 1
// ROOMS Marriott             // 10

struct booking {
  int64_t time;
  string hotel_name;
  int client_id;
  uint32_t room_count;
};

class HotelsManager {
public:

  void Book(int64_t time, string hotel_name, int client_id, uint32_t room_count) {
    booking b = {time, hotel_name, client_id, room_count};
    this->current_time = time;
    this->bookings.push(b);
    this->hotel_clients[hotel_name][client_id] += room_count;
    this->hotel_rooms[hotel_name] += room_count;
    this->Adjust();
  }

  int Clients(string hotel_name) {
    if ( !this->hotel_clients.count(hotel_name) ) {
      return 0;
    }
    return this->hotel_clients[hotel_name].size();
  }

  int Rooms(string hotel_name)  {
    if ( !this->hotel_rooms.count(hotel_name) ) {
      return 0;
    }
    return this->hotel_rooms[hotel_name];
  }

private:
  int64_t day = 86400;
  int64_t current_time = 0;
  queue<booking> bookings;
  map<string, map<int, int>> hotel_clients;
  map<string, uint32_t> hotel_rooms;

  void Adjust() {
    while ( (!this->bookings.empty()) && 
            (this->bookings.front().time <= (this->current_time - this->day)) ) {
      booking f = this->bookings.front();
      this->hotel_rooms[f.hotel_name] -= f.room_count;
      this->hotel_clients[f.hotel_name][f.client_id] -= f.room_count;
      if ( this->hotel_clients[f.hotel_name][f.client_id] == 0 ) {
        this->hotel_clients[f.hotel_name].erase(f.client_id);
      }
      this->bookings.pop();
    }
  }

};

void TestClients() {
  {
    HotelsManager bm;
    ASSERT_EQUAL(bm.Clients("Marriott"), 0);
    ASSERT_EQUAL(bm.Rooms("Marriott"), 0);
    bm.Book(10, "FourSeasons", 1, 2);
    bm.Book(10, "Marriott", 1, 1);
    bm.Book(86409, "FourSeasons", 2, 1);
    ASSERT_EQUAL(bm.Clients("FourSeasons"), 2);
    ASSERT_EQUAL(bm.Rooms("FourSeasons"), 3);
    ASSERT_EQUAL(bm.Clients("Marriott"), 1);
    bm.Book(86410, "Marriott", 2, 10);
    ASSERT_EQUAL(bm.Rooms("FourSeasons"), 1);
    ASSERT_EQUAL(bm.Rooms("Marriott"), 10);
  }
  {
    HotelsManager bm;
    bm.Book(0, "q", 0, 1);
    ASSERT_EQUAL(bm.Clients("q"), 1);
    ASSERT_EQUAL(bm.Rooms("q"), 1);
    bm.Book(10, "q", 0, 3);
    ASSERT_EQUAL(bm.Clients("q"), 1);
    ASSERT_EQUAL(bm.Rooms("q"), 4);
    bm.Book(86411, "q", 3, 1);
    ASSERT_EQUAL(bm.Clients("q"), 1);
    ASSERT_EQUAL(bm.Rooms("q"), 1);
  }
  {
    HotelsManager bm;
    bm.Book(0, "hotel", 1, 1);
    bm.Book(86500, "hotel2", 1, 1);
    ASSERT_EQUAL(bm.Clients("hotel"), 0);
  }
}

int main() {
  TestClients();

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  HotelsManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type, hotel_name;
    cin >> query_type;

    if (query_type == "BOOK") {
      long long int time;
      int client_id;
      short int room_count;

      cin >> time >> hotel_name >> client_id >> room_count;
      manager.Book(time, hotel_name, client_id, room_count);
    } else if (query_type == "CLIENTS") {
      cin >> hotel_name;
      cout << setprecision(6) << manager.Clients(hotel_name) << "\n";
    } else if (query_type == "ROOMS") {
      cin >> hotel_name;
      cout << setprecision(6) << manager.Rooms(hotel_name) << "\n";
    }
  }

  return 0;
}
