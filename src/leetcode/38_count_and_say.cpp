#include <bits/stdc++.h>

std::string countAndSay(int n) {
    std::string result = "1"; 
    for (int i=1; i < n; i++) {
        result = say(result); 
    }
    return result;
}

std::string say(std::string& prev) {
    std::string result = "";
    char prevChar = prev[0];
    int counter = 0;
    for (int i=0; i < prev.size(); i++) {
        if (prev[i] == prevChar) {
            counter++;  
        } else {
            result.push_back('0' + counter);
            result.push_back(prevChar);
            prevChar = prev[i];
            counter = 1;
        }
    }
    result.push_back('0' + counter);
    result.push_back(prevChar);
    return result;
}

int main() {
    // 1 --> 1
    // 4 --> 1211
    return 0;
}