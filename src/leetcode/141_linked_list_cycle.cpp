#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if (head == nullptr) {
    return false;
  }
  ListNode* slowPointer = head;
  ListNode* fastPointer = head;
  while (fastPointer != nullptr) {
    slowPointer = slowPointer->next;
    fastPointer = fastPointer->next;
    if (fastPointer == nullptr) {
      return false;
    }
    fastPointer = fastPointer->next;
    if (slowPointer == fastPointer) {
      return true; 
    }
  }
  return false;
}

int main() {
    // Inps:
    // [3,2,0,-4]
    // 1
    //
    // true // target
    return 0;
}