#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
int traverse(TreeNode* node, int depth, int maxDepth) {
  if (depth > maxDepth) {
    return depth;
  }
  if (node->left) {
    maxDepth = traverse(node->left, depth + 1, maxDepth);
  }
  if (node->right) {
    maxDepth = traverse(node->right, depth + 1, maxDepth);
  }
  return maxDepth;
}

int maxDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }
  return traverse(root, 1, 1);
}

int main() {
  // [3,9,20,null,null,15,7] // tree
  // 3 // target
  return 0;
}