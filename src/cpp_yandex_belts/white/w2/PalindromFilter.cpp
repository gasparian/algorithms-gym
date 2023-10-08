#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    string res;
    if (s.length() == 0) {
        return true;
    }
    for (int i=s.length()-1; i >= 0; i--) {
        res += s[i];
    }
    if (res == s) {
        return true;
    } else {
        return false;
    }
}
 
vector<string> PalindromFilter(vector<string> V, int L) {

    bool status;
    vector<string> result;

    for (int i; i<V.size(); i++) {
        if (V[i].length() >= L) {
            status = IsPalindrom(V[i]);
            if (status == true) {
                result.push_back(V[i]);
            }
        }
    } 
    return result;
}

int main() {

    return 0;
}

