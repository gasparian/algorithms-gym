#include <bits/stdc++.h>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (!strs.size()) return "";
    for (int i = 0; i < (int)strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < (int)strs.size(); j++) {
            if (i == (int)strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main() {
    // ["flower","flow","flight"] --> "fl"
    return 0;
}