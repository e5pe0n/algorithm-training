#include <bits/stdc++.h>
#define MAX_N 300'000
using namespace std;

int N;
string S;
int E[MAX_N];
int W[MAX_N];

void solve() {
  for (int i = 0; i < N - 1; ++i) {
    W[i + 1] = W[i] + (S[i] == 'W');
  }
  for (int i = N - 1; i > 0; --i) {
    E[i - 1] = E[i] + (S[i] == 'E');
  }
  int res = N;
  for (int i = 0; i < N; ++i) {
    res = min(res, E[i] + W[i]);
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}