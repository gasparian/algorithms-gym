#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

int main() {
    std::map<std::vector<std::string>, int> routs; 
    int n;
    int bus_n = 1;
    std::cin >> n;
    ++n;

    for ( int i = 0; i < n; ++i ) {
        std::string command, buf;
        std::getline(std::cin, command);
        std::stringstream ss(command);
        int n_stops = 0;
        ss >> n_stops;

        if ( n_stops > 0 ) {
            std::vector<std::string> stops;
            for (int s=0; s < n_stops; s++) {
                std::string stop;
                ss >> stop;
                stops.push_back(stop);
            }

            if ( stops.size() && !routs.count(stops) ) {
                routs[stops] = bus_n;
                std::cout << "New bus " << bus_n << std::endl;
                bus_n++;
            } else {
                std::cout << "Already exists for " << routs[stops] << std::endl;
            }
        }
    }
    
    return 0;
}