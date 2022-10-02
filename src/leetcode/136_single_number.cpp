#include <bits/stdc++.h>

int singleNumber(std::vector<int>& nums) {
    std::unordered_set<int> lookUp;
    for ( int i=0; i < nums.size(); i++ ) {
        std::unordered_set<int>::const_iterator got = lookUp.find(nums[i]);
        if ( got == lookUp.end() ) {
            lookUp.insert(nums[i]);
        } else {
            lookUp.erase(nums[i]);
        }
    }
    return *(lookUp.begin());
}

int main() {
    // [2,2,1] --> 1
    return 0;
}