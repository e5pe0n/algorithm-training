#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < S.size(); ++i) {
    bool flg = true;
    for (int j = i; j < S.size(); ++j) {
      if (S[j] != T[j - i]) {
        flg = false;
        break;
      }
    }
    if (!flg) {
      continue;
    }
    for (int j = 0; j < i; ++j) {
      if (S[j] != T[j + S.size() - i]) {
        flg = false;
        break;
      }
    }
    if (flg) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}