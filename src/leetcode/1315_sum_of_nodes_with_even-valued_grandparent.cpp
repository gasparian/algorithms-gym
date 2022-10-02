#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumEvenGrandparent(TreeNode* root) {
    int summ = 0;
    check(root, summ);
    return summ;
}
    
void check(TreeNode* node, int &summ, bool even_gp = false, bool even_p = false) {
    if ( even_gp)
        summ += node->val;
    
    even_gp = even_p;
    even_p = false;
    if ( !(node->val % 2) ) 
        even_p = true;
    
    if ( node->left != NULL ) 
        check(node->left, summ, even_gp, even_p);
    if ( node->right != NULL ) 
        check(node->right, summ, even_gp, even_p);
}

int main() {
    // [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5] --> 18
    return 0;
}