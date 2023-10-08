#include <iostream>
#include <string>
#include <map>

using namespace std;

template<typename First, typename Second> Second& GetRefStrict(map<First, Second>& m, First k);
template<typename First, typename Second> 
Second& GetRefStrict(map<First, Second>& m, First k) {
    if ( !m.count(k) )
        throw runtime_error("");
    return m[k];
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    // cout << item << endl; // выведет value
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}