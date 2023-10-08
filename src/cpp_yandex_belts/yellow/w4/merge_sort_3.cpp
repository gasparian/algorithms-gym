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
        size_t part = elements.size() / 3;
        MergeSort(elements.begin(), elements.begin() + part);
        MergeSort(elements.begin() + part, elements.begin() + 2 * part );
        MergeSort(elements.begin() + 2 * part, elements.end());

        vector<typename RandomIt::value_type> tmp;
        merge(elements.begin(), elements.begin() + part, elements.begin() + part, elements.begin() + 2 * part, back_inserter(tmp));
        merge(tmp.begin(), tmp.end(), elements.begin() + 2 * part, elements.end(), range_begin);
    }
}

// int main() {
//   vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
//   MergeSort(begin(v), end(v));
//   for (int x : v) {
//     cout << x << " ";
//   }
//   cout << endl;
//   return 0;
// }