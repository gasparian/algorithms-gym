#include <bits/stdc++.h>

int reverse(int x) {
    int64_t res = 0;
    while ( x ) {
        res = res * 10 + x % 10;
        if ( (res > INT_MAX) || (res < INT_MIN) ) {
            return 0;
        }
        x /= 10;
    }
    return res;
}

int main() {
    // 123 --> 321
    return 0;
}