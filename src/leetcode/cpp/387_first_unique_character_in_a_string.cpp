#include <bits/stdc++.h>

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> m;
    if ( (int)s.size() == 1 ) {
        return 0;
    }
    for ( int i=0; i < (int)s.size(); i++ ) {
        auto res = m.find(s[i]);
        if ( res == m.end() ) {
            m[s[i]] = i;
            continue;
        }
        m[s[i]] = -1;
    }
    int idx = INT_MAX;
    for (auto it=m.begin(); it != m.end(); it++ ) {
        if ( (it->second < idx) && (it->second != -1) ) {
            idx = it->second;
        }
    }
    idx = (idx < INT_MAX) ? idx : -1;
    return idx;
}

int main() {
    // "leetcode" --> 0
    return 0;
}