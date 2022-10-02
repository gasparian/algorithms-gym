#include <bits/stdc++.h>

int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    for ( int i=0; i < (prices.size() - 1); i++ ) {
        int diff = prices[i+1] - prices[i];
        if (diff > 0) {
            profit += diff;
        }
    }
    return profit;
}

int main() {
    // [7,1,5,3,6,4] --> 7
    return 0;
}