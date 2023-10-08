#include "database.h"

void Database::Add(const Date& date, const string& event) {
    int date_size = this->base[date].size();
    this->base[date].insert(event);

    // increase total objects counter only if the size of the set has changed
    if (this->base[date].size() > date_size) {
        this->base_last_el[date].push_back(event);
    }
}
 
void Database::Print(ostream& out) const {
    for ( auto it=this->base_last_el.begin(); it != this->base_last_el.end(); ++it ) {
        auto it2 = it->second.begin();
        while ( it2 != it->second.end()) {
            out << it->first << ' ' << *it2 << endl;
            it2++;
        }
    }
}

string Database::Last(const Date& date) const {
    stringstream res;
    auto itup = this->base_last_el.upper_bound(date);
    if (  itup != this->base_last_el.begin() ) {
        --itup;
        res << itup->first << ' ' << itup->second.back();
    } else {
        throw invalid_argument("");  
    }
    return res.str();
}
