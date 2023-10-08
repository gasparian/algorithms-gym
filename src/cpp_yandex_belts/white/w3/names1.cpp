#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string getClosest(map<int, string>& names, int& yearIn) {
    string res;
    for ( auto it=names.rbegin(); it!=names.rend(); it++ ) {
        if ( it->first < yearIn ) {
            res = it->second;
            break;
        }
    }
    return res;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    surname[year] = last_name;
  }
  string GetFullName(int year) {

    string nameTmp, surnameTmp;
    int nameFlag = name.count(year);
    int surnameFlag = surname.count(year);

    if ( nameFlag ) {
        nameTmp = name[year];
    } else {
        nameTmp = getClosest(name, year);
    } 

    if ( surnameFlag ) {
        surnameTmp = surname[year];
    } else {
        surnameTmp = getClosest(surname, year);
    } 

    if ( nameTmp.empty() && surnameTmp.empty() ) {
        return "Incognito";
    } else if ( !nameTmp.empty() && surnameTmp.empty() ) {
        return nameTmp + " with unknown last name";
    } else if ( nameTmp.empty() && !surnameTmp.empty() ) {
        return surnameTmp + " with unknown first name";
    } else if ( !nameTmp.empty() && !surnameTmp.empty() ) {
        return nameTmp + " " + surnameTmp;
    }
  }

private:
  map<int, string> name;
  map<int, string> surname;
};

// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullName(year) << endl;
//   }
//   // Incognito
//   // Polina with unknown last name
//   // Polina Sergeeva
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
//   // Polina Sergeeva
//   // Appolinaria Sergeeva
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
//   // Polina Volkova
//   // Appolinaria Volkova
  
//   return 0;
// }
