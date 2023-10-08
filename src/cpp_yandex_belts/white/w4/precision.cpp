#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::ifstream input("input.txt");
    float buf;
    std::cout << std::fixed << std::setprecision(3);
    if ( input.is_open() ) {
        while ( input >> buf ) {
            std::cout << buf << std::endl;
        }
    } else {
        std::cout << "error" << std::endl;
    }
    return 0;
}