#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> res;
    auto greater = find_if(elements.begin(), elements.end(), 
                           [border](const T& el) { return el > border; } );
    for ( auto it = greater; it != elements.end(); ++it ) {
        res.push_back(*it);
    }
    return res;
}

// int main() {
//   for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
//     cout << x << " ";
//   }
//   cout << endl;
  
//   string to_find = "Python";
//   cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//   return 0;
// }
