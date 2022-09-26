#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* makeSplit(std::vector<int>& nums, int lidx, int ridx) {
  if (lidx > ridx) {
    return nullptr;
  }
  int centerIdx = lidx + (ridx - lidx) / 2;
    
  TreeNode* root = new TreeNode(nums[centerIdx]);
  root->left = makeSplit(nums, lidx, centerIdx-1);
  root->right = makeSplit(nums, centerIdx+1, ridx);
  return root;
} 

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
  if (!nums.size()) {
    return nullptr;
  }
  return makeSplit(nums, 0, nums.size()-1); 
}

int main() {
  std::vector<int> inp = {-10,-3,0,5,9};
  sortedArrayToBST(inp);
  // [0,-10,5,null,-3,null,9]
  // [0,-3,9,-10,null,5] // target
  return 0;
}