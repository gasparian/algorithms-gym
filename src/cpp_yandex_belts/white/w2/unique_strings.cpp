#include <map>
#include <string>
#include <set>
#include <iostream>
#include <sstream>

int main() {
    std::set<std::string> s;
    int n;
    std::cin >> n;

    for ( int i = 0; i < n; ++i ) {
        std::string buf;
        std::cin >> buf;
        s.insert(buf);
    }

    std::cout << s.size() << std::endl;

    return 0;
}