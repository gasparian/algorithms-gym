#include <bits/stdc++.h>

int myAtoi(std::string s) {
    int i=0;
    int multiplier = 1;
    int result = 0;
    int upperIntBound = INT_MAX / 10;
    if (s.length() == 0) return 0;
    
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    
    if (i < s.length() && (s[i] == '+' || s[i] == '-' )) {
        multiplier = (s[i++] == '-') ? -1 : 1;
    }
    
    int currentVal = 0;
    int maxCurrentVal = (multiplier == 1) ? 7 : 8;
    int diff = 0;
    while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        currentVal = s[i] - '0';    
        diff = result - upperIntBound;
        if (diff > 0 || (diff == 0 && currentVal >= maxCurrentVal)) {
           return (multiplier == 1) ? INT_MAX : INT_MIN; 
        }  
        result = result * 10 + currentVal; 
        i++;
    }
    
    return result * multiplier;
}

int main() {
    // "42" --> 42
    return 0;
}