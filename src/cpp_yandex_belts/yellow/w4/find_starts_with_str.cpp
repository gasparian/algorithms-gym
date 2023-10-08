#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) { 
    int prefix_size = prefix.size();
    auto bounds = equal_range(range_begin, range_end, prefix, 
    [&prefix_size](const typename RandomIt::value_type &el1, const typename RandomIt::value_type &el2) {
        return el1.substr(0, prefix_size) < el2.substr(0, prefix_size);
    });
    int begin_offset = bounds.first - range_begin;
    int end_offset = bounds.second - range_begin;
    return make_pair(range_begin + begin_offset, range_begin + end_offset);
}

// int main() {
  
//   // Answers:
//   // moscow motovilikha
//   // 2 2
//   // 3 3

//   const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
//   const auto mo_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
//   for (auto it = mo_result.first; it != mo_result.second; ++it) {
//     cout << *it << " ";
//   }
//   cout << endl;
  
//   const auto mt_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
//   cout << (mt_result.first - begin(sorted_strings)) << " " <<
//       (mt_result.second - begin(sorted_strings)) << endl;
  
//   const auto na_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
//   cout << (na_result.first - begin(sorted_strings)) << " " <<
//       (na_result.second - begin(sorted_strings)) << endl;
  
//   return 0;
// }
