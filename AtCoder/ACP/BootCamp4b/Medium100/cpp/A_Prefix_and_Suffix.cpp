#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  string s, t;
  cin >> N >> s >> t;
  for (int i = 0; i < N; ++i) {
    bool flg = true;
    for (int j = 0; j < N - i; ++j) {
      if (s[i + j] != t[j]) {
        flg = false;
        break;
      }
    }
    if (flg) {
      printf("%d\n", N + i);
      return 0;
    }
  }
  printf("%d\n", 2 * N);
}