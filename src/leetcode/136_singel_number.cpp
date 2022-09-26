#include <bits/stdc++.h>

int singleNumber(std::vector<int>& nums) {
  int res = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    res ^= nums[i];
  }
  return res;
}

int main() {
  std::vector<int> inp = {2, 2, 1};
  int res = singleNumber(inp);
  assert(res == 1);
  return 0;
}