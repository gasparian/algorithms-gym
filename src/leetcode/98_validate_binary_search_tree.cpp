#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* node, int* minVal, int* maxVal) {
  if (node == nullptr) {
    return 1;
  }
  if ((minVal != nullptr && node->val <= *minVal) || (maxVal != nullptr && node->val >= *maxVal)) {
    return 0;
  }
  return check(node->left, minVal, &node->val) &&
         check(node->right, &node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
  return check(root, nullptr, nullptr);
}

int main() {
  // [2,1,3] // root
  // check(root)
  // true // target
  return 0;
}
