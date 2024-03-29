#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 7
// ADD -2 5
// ADD 10 4
// ADD 5 8
// GO 4 10 
// GO 4 -2
// GO 5 0
// GO 5 100
//
// 0; 6; 2; 92

class RouteManager {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].insert(finish);
    reachable_lists_[finish].insert(start);
  }

  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
        return result;
    }
    const set<int>& reachable_stations = reachable_lists_.at(start);
    if (!reachable_stations.empty()) {
        const auto lb = reachable_stations.lower_bound(finish);
        if ( lb != reachable_stations.end() ) {
            result = min(result, abs(finish - *lb));
        }
        if ( lb != reachable_stations.begin() ) {
            result = min(result, abs(finish - *prev(lb)));
        }
    }
    return result;
  }

private:
  map<int, set<int>> reachable_lists_;
};

int main() {
  RouteManager routes;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}