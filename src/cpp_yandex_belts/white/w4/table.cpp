#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

int main() {
    std::ifstream input("input.txt");
    std::string buf, val;
    std::string bufN, bufM;   
    int N, M;
    if ( input.is_open() ) {
        std::getline(input, buf);
        std::stringstream s(buf);
        std::getline(s, bufN, ' ');
        std::getline(s, bufM, ' ');
        N = std::stoi(bufN);
        M = std::stoi(bufM);

        for ( int i=0; i < N; ++i ) {
            std::getline(input, buf);
            std::stringstream s(buf);
            for ( int j=0; j < M; ++j) {
                std::getline(s, val, ',');
                std::cout << std::setw(10) << val;
                if ( j < (M-1) ) 
                    std::cout << " ";
            }
            if ( i < (N-1) )
                std::cout << std::endl;
        }

    } else {
        std::cout << "error" << std::endl;
    }

    return 0;
}