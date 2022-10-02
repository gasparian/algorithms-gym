#include <bits/stdc++.h>

void reverseString(std::vector<char>& s) {
    int start = 0, end = s.size()-1;
    while ( start < end ) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
    
void swap(char& x, char& y) {
    if ( x != y ) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

int main() {
    // ["h","e","l","l","o"] --> ["o","l","l","e","h"]
    return 0;
}