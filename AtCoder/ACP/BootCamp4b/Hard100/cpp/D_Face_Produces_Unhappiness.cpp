#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int N, K;
string S;

int main() {
  cin >> N >> K >> S;
  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    ans += S[i + 1] == S[i];
  }
  int left = 0;
  int right = 0;
  int cc_L = 0;
  int cc_R = 0;
  while (right < N) {
    while (right < N && S[right] == 'L') {
      ++right;
    }
    if (right > left) {
      ++cc_L;
    }
    left = right;
    while (right < N && S[right] == 'R') {
      ++right;
    }
    if (right > left) {
      ++cc_R;
    }
    left = right;
  }
  if (cc_L == cc_R) {
    if (K >= cc_L) {
      ans += 2 * (cc_L - 1) + 1;
    } else {
      ans += 2 * K;
    }
  } else {
    ans += 2 * min(K, min(cc_L, cc_R));
  }
  ans = min(ans, N - 1);
  printf("%d\n", ans);
}