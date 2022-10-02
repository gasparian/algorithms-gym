#include <bits/stdc++.h>

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for ( int i=0; i < n; i++ ) {
        reverse(matrix[i], 0, n-1);
    }
    
    // swap values
    for ( int i=0; i < (n-1); i++ ) {
        for ( int j=0; j < (n-1); j++ ) {
            // exclude indeces on the main diagonal
            if ( j < (n-1-i) ) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
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

int main() {
    // [[1,2,3],[4,5,6],[7,8,9]] --> [[7,4,1],[8,5,2],[9,6,3]]
    return 0;
}