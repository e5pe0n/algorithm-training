#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int w = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '.') {
      ++w;
    }
  }
  int b = 0;
  int ans = w;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '#') {
      ++b;
    } else {
      --w;
    }
    ans = min(ans, b + w);
  }
  printf("%d\n", ans);
}