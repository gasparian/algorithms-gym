#include <bits/stdc++.h>

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::vector<std::vector<int>> res{{}};
  std::unordered_set<int> seen;
  std::sort(nums.begin(), nums.end());
  int prevStepResIdx = 0;
  int k;
  for (int i = 0; i < nums.size(); i++) {
    k = 0;
    auto p = seen.insert(nums[i]);
    if (!p.second) {
      k = prevStepResIdx;
    }
    int resSize = res.size();
    for (int j = k; j < resSize; j++) {
      auto ss = res[j];
      ss.push_back(nums[i]);
      res.push_back(ss);
    }
    prevStepResIdx = res.size() - (res.size() - resSize);
  }
  return res;
}

int main() {
  std::vector<int> inp = {1, 2, 2};
  std::vector<std::vector<int>> expected = {{},{1},{1,2},{1,2,2},{2},{2,2}};
  auto res = subsetsWithDup(inp);
  assert(res.size() == expected.size());
  for (int i = 0; i < res.size(); i++) {
    bool eq = std::equal(res[i].begin(), res[i].end(), expected.begin());
    assert(eq == true);
  }
}