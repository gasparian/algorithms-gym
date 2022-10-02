#include <bits/stdc++.h>

std::vector<int> plusOne(std::vector<int>& digits) {
    int i = digits.size() - 1;
    plusOneRec(digits, i);
    return digits;
}

void plusOneRec(std::vector<int>& digits, int i) {
    if ( i < 0 ) {
        digits.insert(digits.begin(), 1);
    } else {
        digits[i] += 1;
        if ( digits[i] > 9 ) {
            digits[i] = 0;
            plusOneRec(digits, i - 1);
        }
    }
}

int main() {
    // [1,2,3] --> [1,2,4]
    return 0;
}