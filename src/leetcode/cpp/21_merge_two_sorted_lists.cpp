#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (l1 == nullptr) {
    return l2;
  } else if (l2 == nullptr) {
    return l1;
  }  
  ListNode* res;
  ListNode* tmp;
  if (l1->val < l2->val) {
      res = l1;
      l1 = l1->next;
  } else {
      res = l2;
      l2 = l2->next;
  }
  tmp = res;
  while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
          tmp->next = l1;
          l1 = l1->next;
      } else {
          tmp->next = l2;
          l2 = l2->next;
      }
      tmp = tmp->next;
  }
  tmp->next = l1 == nullptr ? l2 : l1;
  return res;
}

int main() {
    // Inps:  
    // [1,2,4]
    // [1,3,4]
    // 
    // [1,1,2,3,4,4] // target
    return 0;
}