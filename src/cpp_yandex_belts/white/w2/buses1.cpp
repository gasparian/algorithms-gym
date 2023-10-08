#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

void NEW_BUS(std::map<std::string, std::vector<std::string>>& routs, std::string& bus, std::vector<std::string>& stops) {
    for ( auto& s : stops ) {
        routs[bus].push_back(s);
    }
}

void STOPS_FOR_BUS(std::map<std::string, std::vector<std::string>>& routs, std::string& bus,  std::map<std::string, int>& buses_order) {
    for ( auto& stop : routs[bus] ) {
        std::cout << "Stop " << stop << ": ";
        std::vector<std::string> buses;
        int counter = 0;
        for (std::map<std::string,  std::vector<std::string>>::iterator iter = routs.begin(); iter != routs.end(); ++iter) {
            for ( auto& _stop : iter->second ) {
                if ( (_stop == stop) && (bus != iter->first) ) {
                    buses.push_back(iter->first);
                }
            }
        }
        if ( !buses.size() )
            std::cout << "no interchange";
        // resort buses
        std::map<int, std::string> buses_order_sample;
        for ( auto& bus : buses ) {
            if (buses_order.count(bus))
                buses_order_sample[buses_order[bus]] = bus;
        }
        for ( std::map<int,  std::string>::iterator iter = buses_order_sample.begin(); iter != buses_order_sample.end(); ++iter )
            std::cout << iter->second << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::map<std::string, std::vector<std::string>> routs;
    std::map<std::string, int> buses_order; // store here NEW_BUS commands order
    int n;
    int bus_n = 0;
    std::cin >> n;
    ++n;

    for ( int i = 0; i < n; ++i ) {
        std::string command, buf;
        std::getline(std::cin, command);
        std::stringstream ss(command);
        ss >> buf;

        if ( buf == "NEW_BUS" ) {
            int stop_count;
            std::vector<std::string> stops;
            std::string bus;

            ss >> bus;            
            ss >> stop_count;
            for (int s=0; s < stop_count; s++) {
                std::string stop;
                ss >> stop;
                stops.push_back(stop);
            }
            buses_order[bus] = bus_n++;
            NEW_BUS(routs, bus, stops);

        } else if ( buf == "STOPS_FOR_BUS" ) {
            std::string bus, stop;

            ss >> bus;
            if ( !routs.count(bus) ) 
                std::cout << "No bus" << std::endl;
            else STOPS_FOR_BUS(routs, bus, buses_order);

        } else if ( buf == "ALL_BUSES" ) {
            if ( routs.size() == 0 ) {
                std::cout << "No buses" << std::endl;
            } else {
                for (std::map<std::string,  std::vector<std::string>>::iterator iter = routs.begin(); iter != routs.end(); ++iter) {
                    std::string bus = iter->first;
                    std::cout << "Bus " << bus << ": "; 
                    for ( auto& stop_ : iter->second ) {
                        std::cout << stop_ << " ";
                    }
                    std::cout << std::endl;
                }
            }
        } else if ( buf == "BUSES_FOR_STOP" ) {
            std::string stop;
            std::vector<std::string> buses;

            ss >> stop;
            for (std::map<std::string,  std::vector<std::string>>::iterator iter = routs.begin(); iter != routs.end(); ++iter) {
                std::string bus = iter->first;
                for (auto& _stop : iter->second) {
                    if ( _stop == stop ) {
                        buses.push_back(bus);
                        break;
                    }
                }
            }
            if ( !buses.size() ) {
                std::cout << "No stop";
            } else {
                // resort buses
                std::map<int, std::string> buses_order_sample;
                for ( auto& bus : buses ) {
                    if (buses_order.count(bus))
                        buses_order_sample[buses_order[bus]] = bus;
                }
                for ( std::map<int,  std::string>::iterator iter = buses_order_sample.begin(); iter != buses_order_sample.end(); ++iter )
                    std::cout << iter->second << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

    