#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

char C[2];

int main() {
  string S;
  cin >> S;
  char c = S[0];
  C[0] = '1';
  C[1] = '0';
  int cnt = 0;
  for (int i = 1; i < S.size(); ++i) {
    if (c == S[i]) {
      c = C[c - '0'];
      ++cnt;
    } else {
      c = S[i];
    }
  }
  printf("%d\n", cnt);
}