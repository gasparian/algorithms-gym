#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <map>

using namespace std;

// enum class Lang {
//   DE, FR, IT
// };

// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };

bool operator<(const Region& lhs, const Region& rhs) {
    return (make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
            make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population));
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> uniques;
    int maxx = 0;

    if ( regions.size() == 0 )
        return maxx;

    for ( Region R : regions ) {
        uniques[R]++;
    }

    for ( map<Region, int>::iterator it = uniques.begin(); it != uniques.end(); it++) {
        if ( it->second > maxx )
            maxx = it->second;
    }

    return maxx;
}

// int main() {
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       },
//   }) << endl;
  
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Toulouse",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           31
//       },
//   }) << endl;
  
//   return 0;
// }
