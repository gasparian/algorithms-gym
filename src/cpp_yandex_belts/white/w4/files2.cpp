#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string buf;
    if ( input.is_open() ) {
        while ( std::getline(input, buf) ) {
            output << buf << std::endl;
        }
    } else {
        std::cout << "error" << std::endl;
    }
    return 0;
}