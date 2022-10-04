#include <bits/stdc++.h>

int hammingWeight(uint32_t n) {
  if (n == 0) {
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < (int)sizeof(n)*8; i++) {
    sum += n & 1;
    n = n >> 1;
  }
  return sum;
}

int main() {
  int res = hammingWeight(11);
  assert(res == 3);
  return 0;
}