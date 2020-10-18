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
  vector<int> V{};
  int i = 0;
  while (i < N) {
    int cc = 0;
    while (i < N && S[i] == '1') {
      ++cc;
      ++i;
    }
    V.push_back(cc);
    cc = 0;
    while (i < N && S[i] == '0') {
      ++cc;
      ++i;
    }
    if (cc > 0) {
      V.push_back(cc);
    }
  }
  if (S[N - 1] == '0') {
    V.push_back(0);
  }
  int N_V = V.size();
  int w = min(K * 2 + 1, N_V);
  int t = 0;
  for (int i = 0; i < w; ++i) {
    t += V[i];
  }
  int ans = t;
  for (int i = 2; i + w <= N_V; i += 2) {
    t = t - V[i - 2] - V[i - 1] + V[i + w - 2] + V[i + w - 1];
    ans = max(ans, t);
  }
  printf("%d\n", ans);
}