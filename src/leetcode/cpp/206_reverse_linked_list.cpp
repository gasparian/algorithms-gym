#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* dummy = nullptr; 
  ListNode* node = head;
  ListNode* tmp; 
  while (node != nullptr) {
    tmp = node->next;
    node->next = dummy;
    dummy = node;
    node = tmp;
  }
  return dummy;
}

int main() {
    // [1,2,3,4,5] // inp
    // [5,4,3,2,1] // target
    return 0;
}