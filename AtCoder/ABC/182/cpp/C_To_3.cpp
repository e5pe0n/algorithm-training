#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string N;

int main() {
  cin >> N;
  int M = N.size();
  int res = M;
  for (int i = 1; i < 1 << M; ++i) {
    string t;
    int cnt = 0;
    for (int j = M - 1; j >= 0; --j) {
      if (i >> j & 1) {
        t += N[j];
        ++cnt;
      }
    }
    if (stoll(t) % 3 == 0) {
      res = min(res, M - cnt);
    }
  }
  if (res == M) {
    res = -1;
  }
  printf("%d\n", res);
}