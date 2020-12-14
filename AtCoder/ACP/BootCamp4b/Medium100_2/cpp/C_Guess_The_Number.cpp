#include <bits/stdc++.h>
using namespace std;

int N, M;
int S[3], C[3];
int n[3], cnt[3];

void solve() {
  int res = 0;
  for (int i = 0; i < M; ++i) {
    if (N >= 2 && S[i] == 1 && C[i] == 0) {
      res = -1;
      break;
    }
    if (cnt[S[i] - 1] > 0 && n[S[i] - 1] != C[i]) {
      res = -1;
      break;
    }
    n[S[i] - 1] = C[i];
    ++cnt[S[i] - 1];
  }
  if (res == 0) {
    if (N >= 2) {
      n[0] = max(n[0], 1);
    }
    for (int i = 0; i < N; ++i) {
      res += n[i] * (int)pow(10, N - 1 - i);
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> S[i] >> C[i];
  }
  solve();
}