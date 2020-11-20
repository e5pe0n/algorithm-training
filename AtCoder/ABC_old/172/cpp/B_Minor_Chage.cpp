#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int cnt = 0;
  for (int i = 0; i < S.size(); ++i) {
    cnt += S[i] != T[i];
  }
  printf("%d\n", cnt);
}