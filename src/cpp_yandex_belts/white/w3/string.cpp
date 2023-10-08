#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class ReversibleString {
    public:
        ReversibleString() {}
        ReversibleString(string sIn) {
            vector<char> In(sIn.begin(), sIn.end());
            s = In;
        }
        void Reverse() {
            reverse(s.begin(), s.end());
        }
        string ToString() const {
            string out;
            for ( auto& c : s )
                out += c;
            return out;
        }
    private:
        vector<char> s;
};

// int main() {
//   ReversibleString s("live");
//   s.Reverse();
//   cout << s.ToString() << endl;
//   // evil
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   string tmp = s_ref.ToString();
//   cout << tmp << endl;
//   // live
  
//   ReversibleString empty;
//   cout << '"' << empty.ToString() << '"' << endl;
//   // ""
  
//   return 0;
// }