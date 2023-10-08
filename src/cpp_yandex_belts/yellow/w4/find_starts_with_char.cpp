#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    string str(1, prefix); 
    auto bounds = equal_range(range_begin, range_end, str, 
    [](const typename RandomIt::value_type &el1, const typename RandomIt::value_type &el2) {
        return el1[0] < el2[0];
    });
    int begin_offset = bounds.first - range_begin;
    int end_offset = bounds.second - range_begin;
    return make_pair(range_begin + begin_offset, range_begin + end_offset);
}

// int main() {

//   // Answers:  
//   // moscow murmansk
//   // 2 2
//   // 3 3

//   const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  
//   const auto m_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
//   for (auto it = m_result.first; it != m_result.second; ++it) {
//     cout << *it << " ";
//   }
//   cout << endl;
  
//   const auto p_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
//   cout << (p_result.first - begin(sorted_strings)) << " " <<
//       (p_result.second - begin(sorted_strings)) << endl;
  
//   const auto z_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
//   cout << (z_result.first - begin(sorted_strings)) << " " <<
//       (z_result.second - begin(sorted_strings)) << endl;
  
//   return 0;
// }
