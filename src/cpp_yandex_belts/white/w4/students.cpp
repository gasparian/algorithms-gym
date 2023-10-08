#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> dmy;
};

int main() {
    std::vector<Student> students;
    std::string buf, val, command, s_idx;
    int N, M, idx;

    std::getline(std::cin, buf);
    N = std::stoi(buf);

    if ( (N < 0) || (N > 10000) ) {
        std::cout << "bad request" << std::endl;
        return 0;
    }

    if ( N > 0 ) {
        for ( int i=0; i < N; ++i ) {
            std::vector<int> dmy;
            std::string n;

            std::getline(std::cin, buf);
            std::stringstream s(buf);
            // get name
            std::getline(s, val, ' ');
            n += val + ' ';
            std::getline(s, val, ' ');
            n += val;

            int j = 0;
            while ( j < 3 ) {
                std::getline(s, val, ' ');
                dmy.push_back(std::stoi(val));
                j++;
            }
            students.push_back({n, dmy});
        }
    }

    // read commands
    std::getline(std::cin, buf);
    M = std::stoi(buf);

    if ( (M < 0) || (M > 10000) ) {
        std::cout << "bad request" << std::endl;
        return 0;
    }

    if ( M > 0 ) {
        for (int i=0; i < M; i++ ) {
            std::getline(std::cin, buf);
            std::stringstream s(buf);
            std::getline(s, command, ' ');
            std::getline(s, s_idx, ' ');
            idx = std::stoi(s_idx) - 1;

            if ( (idx < 0) || (idx > (N-1)) ) {
                std::cout << "bad request" << std::endl;
                continue;
            }

            if ( command == "name" ) {
                std::cout << students[idx].name << std::endl;
            } else if ( command == "date" ) {
                for ( int j=0; j < 3; ++j ) {
                    std::cout << students[idx].dmy[j];
                    if ( j < 2 )
                        std::cout << '.';
                }
                std::cout << std::endl;
            } else {
                std::cout << "bad request" << std::endl;
            }
        }
    }

    // Ivan Ivanov
    // 3.3.1903
    // bad request

    return 0;
}