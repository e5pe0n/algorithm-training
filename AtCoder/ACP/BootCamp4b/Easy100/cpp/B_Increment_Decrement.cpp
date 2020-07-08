#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int x = 0;
  int res = x;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'I') {
      ++x;
      res = max(res, x);
    } else if (S[i] == 'D') {
      --x;
    }
  }
  printf("%d\n", res);
}