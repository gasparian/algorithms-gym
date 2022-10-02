#include <bits/stdc++.h>

bool isAnagram(std::string s, std::string t) {
    if ( s.size() != t.size() ) {
        return false;
    }
    int alphabet[26] = {0};
    for ( int i=0; i < s.size(); i++ ) {
        // 97 is the offset since 'a' == 97 Dec
        int idx = (int)s[i] - 97;
        alphabet[idx]++;
    }
    for ( int i=0; i < t.size(); i++ ) {
        int idx = (int)t[i] - 97;
        alphabet[idx]--;
        if ( alphabet[idx] < 0 ) {
            return false;
        }
    }
    return true;
}

int main() {
    // "anagram"\n"nagaram" --> true
    return 0;
}