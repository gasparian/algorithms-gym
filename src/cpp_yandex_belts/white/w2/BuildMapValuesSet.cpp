#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for (map<int,  string>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
        s.insert(iter->second);
    }
    return s;
}

// int main() {
//     const map<int, string> m = {{1, "Mike"}, {2, "Drake"}, {3, "Mike"}};
//     set<string> s = BuildMapValuesSet(m);

//     std::cout << s.size() << std::endl;

//     return 0;
// }