#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int cnt = 0;
  for (int i = A; i <= B; ++i) {
    string s = to_string(i);
    int l = 0;
    int r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
      ++l;
      --r;
    }
    if (l >= r) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
}