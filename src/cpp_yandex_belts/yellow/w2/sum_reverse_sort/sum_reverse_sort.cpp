#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    string res;
    for (int i=s.length()-1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}