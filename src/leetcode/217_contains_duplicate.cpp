#include <bits/stdc++.h>

bool containsDuplicate(std::vector<int>& nums) {
    std::map<int, bool> seen;
    
    for ( int& n : nums ) {
        if ( !seen[n] ) {
            seen[n] = true;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    // [1,2,3,1] --> true
    return 0;
}