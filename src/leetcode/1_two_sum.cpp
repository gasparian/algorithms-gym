#include <bits/stdc++.h>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> m;
    std::vector<int> res(2);
    for ( int i=0; i < nums.size(); i++ ) {
        int diff = target - nums[i];
        std::unordered_map<int, int>::const_iterator it = m.find(diff);
        if ( (it != m.end()) && (it->second != i) ) {
            res = {it->second, i};
            break;
        }
        m[nums[i]] = i;
    }
    return res;
}

int main() {
    // [2,7,11,15] 9 --> [0,1]
    return 0;
}