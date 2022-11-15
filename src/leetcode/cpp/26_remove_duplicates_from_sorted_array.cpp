#include <bits/stdc++.h>

int removeDuplicates(std::vector<int>& nums) {
    if ( !nums.size() ) {
        return 0;
    }
    
    int num = nums[0];
    for ( std::vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ) {
        if ( *it == num ) {
            nums.erase(it);
        } else {
            num = *it;
            it++;
        }
    }
    
    return static_cast<int>(nums.size());
}

int main() {
    // [1,1,2] --> [1,2]
    return 0;
}