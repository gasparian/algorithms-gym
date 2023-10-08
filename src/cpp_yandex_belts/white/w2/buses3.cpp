#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

int main() {
    std::map<std::set<std::string>, int> routs; 
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
            std::set<std::string> stops;
            for (int s=0; s < n_stops; s++) {
                std::string stop;
                ss >> stop;
                stops.insert(stop);
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