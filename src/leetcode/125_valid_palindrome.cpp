#include <bits/stdc++.h>

bool isPalindrome(std::string s) {   
   if ((int)s.size() <= 1) {
       return true;
   }
   char ch1, ch2; 
   for (int i = 0, j=(int)s.size()-1; i < j;) {
      if (!isalnum(s[i])) {
          i++;
          continue;
      }
       
      if (!isalnum(s[j])) {
          j--;
          continue;
      }
      ch1 = tolower(s[i]);
      ch2 = tolower(s[j]);
       
      if (ch1 != ch2) {
          return false;
      }
       
      i++;
      j--;
   }
   return true;
}

int main() {
    // "A man, a plan, a canal: Panama" --> true
    return 0;
}