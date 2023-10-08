#include <iostream>
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

int main() {
    return 0;
}

