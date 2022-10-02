#include <bits/stdc++.h>

std::vector<int> decompressRLElist(std::vector<int>& nums) {
    std::vector<int> res;
    for ( auto it=nums.begin(); it < nums.end() - 1; it = it + 2) {
        fill_n(back_inserter(res), *it, *(it+1));
    }
    return res;
}

int main() {
    // nums = [1,2,3,4] --> [2,4,4,4]
    // nums = [1,1,2,3] --> [1,3,3]
    return 0;
}