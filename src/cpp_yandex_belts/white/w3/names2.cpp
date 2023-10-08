#include <map>
#include <vector>
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

string getClosestSet(map<int, string>& names, int& yearIn, string& orig) {
    vector<string> res;
    string ignore = orig;
    string out;
    for ( auto it=names.rbegin(); it!=names.rend(); it++ ) {
        if ( (it->first < yearIn) && ( ignore != it->second ) ) {
            res.push_back(it->second);
            ignore = it->second;
        }
    }
    if ( res.size() > 0 ) {
        for (auto el : res ) {
            out += el + ", ";
        }
        // delete the last space and comma if it exists
        if ( !out.empty() )
            out.pop_back();
            out.pop_back();
    }
    return out;
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
  string GetFullNameWithHistory(int year) {
    vector<string> lastNamesContainer, lastSurnamesContainer;

    string res, nameTmp, surnameTmp, nameHist, surnameHist;
    int nameFlag = name.count(year);
    int surnameFlag = surname.count(year);

    if ( nameFlag ) {
        nameTmp = name[year];
    } else {
        nameTmp = getClosest(name, year);
    } 
    if ( name.size() > 1 )
        nameHist = getClosestSet(name, year, nameTmp);

    if ( surnameFlag ) {
        surnameTmp = surname[year];
    } else {
        surnameTmp = getClosest(surname, year);
    } 
    if ( surname.size() > 1 )
        surnameHist = getClosestSet(surname, year, surnameTmp);

    if ( nameTmp.empty() && surnameTmp.empty() ) {
        return "Incognito";
    } else if ( !nameTmp.empty() && surnameTmp.empty() ) {
        if ( !nameHist.empty() )
            return nameTmp + " (" + nameHist + ")" + " with unknown last name";
        else
            return nameTmp + " with unknown last name";
    } else if ( nameTmp.empty() && !surnameTmp.empty() ) {
        if ( !surnameHist.empty() )
            return surnameTmp + " (" + surnameHist + ")" + " with unknown first name";
        else
            return surnameTmp + " with unknown first name";
    } else if ( !nameTmp.empty() && !surnameTmp.empty() ) {
        if ( !nameHist.empty() )
            res += nameTmp + " (" + nameHist + ")";
        else 
            res += nameTmp;

        if ( !surnameHist.empty() )
            res += " " + surnameTmp + " (" + surnameHist + ")";
        else 
            res += " " + surnameTmp;
        return res;
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
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//     // Incognito
//     // Polina with unknown last name
//     // Polina Sergeeva
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//     // Polina Sergeeva
//     // Appolinaria (Polina) Sergeeva
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//     // Polina Volkova (Sergeeva)
//     // Appolinaria (Polina) Volkova (Sergeeva)
  
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   cout << person.GetFullNameWithHistory(1990) << endl;
//   // Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
  
//   person.ChangeFirstName(1966, "Pauline");
//   cout << person.GetFullNameWithHistory(1966) << endl;
//   // Pauline (Polina) with unknown last name
  
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//     // Sergeeva with unknown first name
//     // Pauline (Polina) Sergeeva
  
//   person.ChangeLastName(1961, "Ivanova");
//   cout << person.GetFullNameWithHistory(1967) << endl;
//   // Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
  
//   return 0;
// }

// int main() {
//   Person person;

//   person.ChangeFirstName(1900, "Eugene");
//   person.ChangeLastName(1900, "Sokolov");
//   person.ChangeLastName(1910, "Sokolov");
//   person.ChangeFirstName(1920, "Evgeny");
//   person.ChangeLastName(1930, "Sokolov");
//   cout << person.GetFullNameWithHistory(1940) << endl;
//   // Evgeny (Eugene) Sokolov
  
//   return 0;
// }