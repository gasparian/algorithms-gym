#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root) {
  if (root == nullptr) {
    return 1;
  }
  std::queue<TreeNode*> q;
  TreeNode* t1;
  TreeNode* t2;
  q.push(root);
  q.push(root);
  while (!q.empty()) {
    t1 = q.front();
    q.pop();
    t2 = q.front();
    q.pop();
    if (t1 == nullptr && t2 == nullptr) {
        continue;
    }
    if (t1 == nullptr || t2 == nullptr) {
        return 0;
    }
    if (t1->val != t2->val) {
        return 0;
    }
    q.push(t1->left);
    q.push(t2->right);
    q.push(t1->right);
    q.push(t2->left);
  }
  return 1;
}

int main() {
  // [1,2,2,3,4,4,3] // input tree
  // isSymmetric(node);
  // true // target
  return 0;
}