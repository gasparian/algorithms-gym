#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  if (root == nullptr) {
      return res; 
  }
  TreeNode* curr;
  int qsize;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
      qsize = q.size();
      std::vector<int> v;
      for (int i=0; i < qsize; i++) {
          curr = q.front();
          q.pop();
          v.push_back(curr->val);
          if (curr->left) {
              q.push(curr->left);
          }
          if (curr->right) {
              q.push(curr->right);
          }
      }
      res.push_back(v);
  }
  return res;
}

int main() {
  // [3,9,20,null,null,15,7]
  // [[3],[9,20],[15,7]] // target
  return 0;
}
