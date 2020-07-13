#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int C[26][2]{};

int main() {
  int N;
  string S;
  cin >> N >> S;
  for (int i = 0; i < 26; ++i) {
    C[i][0] = -1;
    C[i][1] = -1;
  }
  for (int i = 0; i < N; ++i) {
    int c = S[i] - 'a';
    if (C[c][0] == -1) {
      C[c][0] = i;
    } else {
      C[c][1] = i;
    }
  }
  int res = 0;
  for (int i = 0; i < N - 1; ++i) {
    int cnt = 0;
    for (int j = 0; j < 26; ++j) {
      if (C[j][0] <= i && i < C[j][1]) {
        ++cnt;
      }
    }
    res = max(res, cnt);
  }
  printf("%d\n", res);
}