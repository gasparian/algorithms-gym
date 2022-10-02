#include <bits/stdc++.h>

void moveZeroes(std::vector<int>& nums) {
    for ( int lastNonZero=0, cur=0; cur < nums.size(); cur++ ) {
        if ( nums[cur] != 0 ) {
            swap(nums[lastNonZero++], nums[cur]);
        }
    }
}
    
void swap(int& x, int& y) {
    if ( x != y ) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

int main() {
    // [0,1,0,3,12] --> [1,3,12,0,0]
    return 0;
}