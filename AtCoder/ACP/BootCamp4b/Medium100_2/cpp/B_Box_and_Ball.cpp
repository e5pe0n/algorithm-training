#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll X[MAX_M], Y[MAX_M];
ll C[MAX_N];
bool R[MAX_N];

void solve() {
  fill(C, C + N, 1);
  R[0] = true;
  for (int i = 0; i < M; ++i) {
    --C[X[i]];
    ++C[Y[i]];
    if (R[X[i]]) {
      R[Y[i]] = true;
    }
    if (C[X[i]] == 0) {
      R[X[i]] = false;
    }
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res += R[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }
  solve();
}