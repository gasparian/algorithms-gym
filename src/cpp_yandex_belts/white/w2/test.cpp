#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void AddWorld(string s) {
    s += " world";
}

void AddWorldVersion2(string& s) {
    s += " world";
}

void Swap(string a, string b) {
    auto tmp = a;
    a = b;
    b = tmp;
    cout << a << " " << b << endl;
}

int main() {
    map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
    m[2] = "two";
    m.erase(1);
    m[3] = "three";
    m.erase(4);
    m[5] = "five";
    cout << m.size();
    return 0;
}
