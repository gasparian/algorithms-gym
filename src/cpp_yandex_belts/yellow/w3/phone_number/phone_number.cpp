#include "phone_number.h"
#include <iostream>
#include <sstream>
#include <vector>

PhoneNumber::PhoneNumber(const string &international_number) {
    string buf;
    vector<string> parsed;
    stringstream ss(international_number);
    int counter = 0;
    while ( getline(ss, buf, '-') ) {
        parsed.push_back(buf);
        if ( counter >= 3 )
            parsed[2] += "-" + buf;
        else
            counter++;
    }

    if ( parsed.size() < 3 )
        throw invalid_argument("Must contain country code, city code and local number separated with `-`");

    if ( parsed[0][0] != '+' )
        throw invalid_argument("The country code must be starting with `+`");

    this->country_code_ = parsed[0].substr(1);
    this->city_code_ = parsed[1];
    this->local_number_ = parsed[2];
}

string PhoneNumber::GetCountryCode() const {
    return this->country_code_;
}

string PhoneNumber::GetCityCode() const {
    return this->city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return this->local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + this->country_code_ + "-" + this->city_code_ + "-" + this->local_number_;
}