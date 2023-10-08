#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Weather {
public:
  Weather(const string& new_state, int new_temperature) {
    state = new_state;
    temperature = new_temperature;
    cout << 'c';
  }
  ~Weather() {
    cout << 'd';
  }
private:
  string state;
  int temperature;
};

// void f(int x) {
//   cout << 'a';
//   if (x % 2 == 0) {
//     Weather weather("rain", 5);
//     cout << 'b';
//     return;
//   }
//   Weather weather2("fog", 4);
//   cout << 'e';
// }

void f(int x) {
  cout << 'a';
  if (x % 2 == 1) {
    Weather weather("rain", 5);
    cout << 'b';
  }
  Weather weather2("fog", 4);
  cout << 'e';
}

Weather GetMayWeather(int day) {
  if (day == 9) {
    cout << 'b';
    return {"clear", 10};
  } else {
    cout << 'b';
    return {"cloudy", 10};
  }
}

// // abcedabcedf
// int main() {
//   vector<int> days(2, 1);
//   for (int day : days) {
//     cout << 'a';
//     Weather weather = GetMayWeather(day);
//     cout << 'e';
//   }
//   cout << 'f';
//   return 0;
// }

int main() {
  f(11);
  return 0;
}


// int main() {
//   cout << 'a';
//   Weather weather("snow", -5);
//   cout << 'b';
//   return 0;
// }
