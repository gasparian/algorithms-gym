#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next; 
}

int main() {
    // [4,5,1,9]
    // 5

    // [4,1,9] // target
    return 0;
}