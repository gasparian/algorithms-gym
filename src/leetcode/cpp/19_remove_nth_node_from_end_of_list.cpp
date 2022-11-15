#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy = ListNode();
  dummy.next = head;
  ListNode* first = &dummy; // n + 1; fast pointer
  ListNode* second = &dummy; // i; slow pointer
  for (int i=0; i < n+1; i++) {
      first = first->next;
  }
  while (first != nullptr) {
      first = first->next;
      second = second->next;
  }
  // so the second pointer will be at size - n
  second->next = second->next->next; 
  return dummy.next; 
}

int main() {
    // Inps:
    // [1,2,3,4,5]
    // 2
    // 
    // [1,2,3,5] // target
    return 0;
}