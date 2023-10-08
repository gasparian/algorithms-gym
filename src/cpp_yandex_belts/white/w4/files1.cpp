#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    std::string buf;
    if ( input.is_open() ) {
        while ( std::getline(input, buf) ) {
            std::cout << buf << std::endl;
        }
    } else {
        std::cout << "error" << std::endl;
    }

    // input.clear();
    // input.seekg(0);
    // std::ofstream output("output.txt");
    // while ( input ) {
    //     std::string buf;
    //     std::getline(input, buf);
    //     if ( buf.back() == '\n' ) 
    //         buf.pop_back();
    //     if ( !buf.empty() )
    //         output << buf << std::endl;
    // }

    return 0;
}