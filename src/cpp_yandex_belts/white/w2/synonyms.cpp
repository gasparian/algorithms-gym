#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

int main() {
    std::map<std::string, std::set<std::string>> dict;
    int n;
    std::cin >> n;
    ++n;

    for ( int i = 0; i < n; ++i ) {
        std::string command, buf;
        std::getline(std::cin, command);
        std::stringstream ss(command);
        ss >> buf;

        if ( buf == "ADD" ) {
            std::string word1, word2;
            ss >> word1;
            ss >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);

        } else if ( buf == "COUNT" ) {
            std::string word;
            ss >> word;
            int res = dict[word].size();
            std::cout << res << std::endl;

        } else if ( buf == "CHECK" ) {
            std::string word1, word2;
            ss >> word1;
            ss >> word2;
            if ( dict[word1].count(word2) || dict[word2].count(word1))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
    }

    return 0;
}