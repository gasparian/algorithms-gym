#include <iostream>
#include <algorithm> //min_element
#include <vector> // vector<>
#include <iterator> //begin, end
using namespace std;

int main() {
    string a, b, c;
    std::vector<string> v;
    cin >> a >> b >> c;
    v = {a, b, c};
    auto minn = std::min_element(begin(v),end(v));
    cout << *minn;

    return 0;
}
