#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int res = 0;
  for (int i = 0; i < S.size() - 1; ++i) {
    if (S[i + 1] != S[i]) {
      ++res;
    }
  }
  printf("%d\n", res);
}