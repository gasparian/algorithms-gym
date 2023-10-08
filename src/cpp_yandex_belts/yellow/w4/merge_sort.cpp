#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int dist = range_end - range_begin;
    if ( dist < 2 ) {
        return;
    } else {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        size_t middle = elements.size() / 2;
        MergeSort(elements.begin(), elements.begin() + middle);
        MergeSort(elements.begin() + middle, elements.end());
        merge(elements.begin(), elements.begin() + middle, elements.begin() + middle, elements.end(), range_begin);
    }
}

// int main() {
//   vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
//   // vector<int> v = {6, 5, 4, 3, 2, 1};
//   MergeSort(begin(v), end(v));
//   for (int x : v) {
//     cout << x << " ";
//   }
//   cout << endl;
//   return 0;
// }