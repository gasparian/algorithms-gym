#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return true;
  }
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
    
  slow = reverseList(slow);        
  fast = head;
  while (slow != nullptr) {
    if (slow->val != fast->val) {
      return false;
    }
    slow = slow->next;
    fast = fast->next; 
  }
  return true;
}
    
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
    // [1,2,2,1] // inp
    // true // target
    return 0;
}