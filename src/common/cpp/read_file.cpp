#include <string>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input;
    input.open("input.txt");

    if (!input.is_open()) {
        std::exit(EXIT_FAILURE);
    }

    std::string str;
    while (std::getline(input, str)) {
        std::istringstream iss(str);
        std::string token;
        while (std::getline(iss, token, '\t')) {
            //...
        }
    }
    input.close();
    return 0;
}