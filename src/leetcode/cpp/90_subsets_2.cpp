#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::vector<std::vector<int>> res{{}};
  std::unordered_set<int> seen;
  std::sort(nums.begin(), nums.end());
  int prevStepResIdx = 0;
  int k, res_size;
  for (int i = 0; i < (int)nums.size(); i++) {
    k = 0;
    auto p = seen.insert(nums[i]);
    if (!p.second) {
      k = prevStepResIdx;
    }
    int prev_res_size = static_cast<int>(res.size());
    for (int j = k; j < prev_res_size; j++) {
      auto ss = res[j];
      ss.push_back(nums[i]);
      res.push_back(ss);
    }
    res_size = static_cast<int>(res.size());
    prevStepResIdx = res_size - (res_size - prev_res_size);
  }
  return res;
}

int main() {
  std::vector<int> inp = {1, 2, 2};
  std::vector<std::vector<int>> expected = {{},{1},{1,2},{1,2,2},{2},{2,2}};
  auto res = subsetsWithDup(inp);
  assert(res.size() == expected.size());
  for (int i = 0; i < (int)res.size(); i++) {
    bool eq = std::equal(res[i].begin(), res[i].end(), expected[i].begin());
    assert(eq == true);
  }
  return 0;
}