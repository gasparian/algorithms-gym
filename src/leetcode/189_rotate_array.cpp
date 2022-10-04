#include <bits/stdc++.h>

void reverse(std::vector<int>& nums, int start, int end) {
    int temp;
    while ( start < end ) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
    
void rotate(std::vector<int>& nums, int k) {
    int size = static_cast<int>(nums.size());
    k = k % size;
    reverse(nums, 0, size-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, size-1);
    return;
}

int main() {
    // [1,2,3,4,5,6,7] 3 --> [5,6,7,1,2,3,4] 
    return 0;
}