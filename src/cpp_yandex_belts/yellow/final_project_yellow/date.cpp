#include "date.h"

Date::Date() {
    date = {0, 0, 0};
}

Date::Date(int year, int month, int day) {
    date = {year, month, day};
}

int Date::GetYear() const {
    return date[0];
}
int Date::GetMonth() const {
    return date[1];
}
int Date::GetDay() const {
    return date[2];
}

bool operator<(const Date& lhs, const Date& rhs) {
    if ( (lhs.GetYear() < rhs.GetYear()) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() < rhs.GetMonth())) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() < rhs.GetDay())) )
        return true;
    return false;
}

bool operator==(const Date& lhs, const Date& rhs) {
    if ( (lhs.GetYear() == rhs.GetYear()) &&
         (lhs.GetMonth() == rhs.GetMonth()) && 
         (lhs.GetDay() == rhs.GetDay()) )
         return true;
    return false;
}

bool operator!=(const Date& lhs, const Date& rhs) {
    if ( !(lhs == rhs) )
        return true;
    return false;
}

bool operator<=(const Date& lhs, const Date& rhs) {
    if ( (lhs < rhs) | (lhs == rhs) )
        return true;
    return false;
}

bool operator>(const Date& lhs, const Date& rhs) {
    if ( (lhs.GetYear() > rhs.GetYear()) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() > rhs.GetMonth())) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() > rhs.GetDay())) )
        return true;
    return false;
}

bool operator>=(const Date& lhs, const Date& rhs) {
    if ( (lhs > rhs) | (lhs == rhs) )
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Date& date) {
    out << setw(4) << setfill('0') << to_string(date.GetYear()) << '-'
        << setw(2) << setfill('0') << to_string(date.GetMonth()) << '-'
        << setw(2) << setfill('0') << to_string(date.GetDay());   
    return out;
}

void filter_stream(string& c, istringstream& ss, int& i, bool day_flag) {
    if ( ss.peek() == '-' ) {
        ss.ignore(1);
        if ( !isdigit(ss.peek()) ) {
            throw invalid_argument("Wrong date format: " + c);  
        } else {
            ss >> i;
            i *= -1;
        }
    } else if ( (ss.peek() == '+') | isdigit(ss.peek()) ) {
        ss >> i;
        if ( day_flag ) {
            string n;
            getline(ss, n);
            char next_char = n[0];
            if ( !isdigit(next_char) && !n.empty() && (next_char != ' ') ) {
                throw invalid_argument("Wrong date format: " + c);
            }
        }
        
    } else {
        throw invalid_argument("Wrong date format: " + c);
    }
}

Date ParseDate(istream& is) {

    int y, m, d;
    string c;
    is >> c;
    istringstream ss(c);

    ss >> y;
    if ( ss.peek() != '-' )
        throw invalid_argument("Wrong date format: " + c);
    ss.ignore(1);

    filter_stream(c, ss, m, false);

    if ( ss.peek() != '-' )
        throw invalid_argument("Wrong date format: " + c);
    ss.ignore(1);
    filter_stream(c, ss, d, true);

    if ( (m < 1) | (m > 12) )
        throw invalid_argument("Month value is invalid: " + to_string(m));  

    if ( (d < 1) | (d > 31) )
        throw invalid_argument("Day value is invalid: " + to_string(d));  

    Date date(y, m, d);
    return date;
}

