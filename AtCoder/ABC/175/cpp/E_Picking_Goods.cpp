#include <bits/stdc++.h>
#define MAX_R 3000
#define MAX_C 3000
using namespace std;
typedef long long ll;

ll R, C, K;
ll V[MAX_R + 1][MAX_C + 1];
ll dp[2][MAX_C + 1][4];

void solve() {
  ll(*prv)[4] = dp[0];
  ll(*nxt)[4] = dp[1];
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      for (int k = 0; k < 4; ++k) {
        nxt[j][0] = max(nxt[j][0], prv[j][k]);
        nxt[j][k] = max(nxt[j][k], nxt[j - 1][k]);
      }
      for (int k = 2; k >= 0; --k) {
        nxt[j][k + 1] = max(nxt[j][k + 1], nxt[j][k] + V[i][j]);
      }
    }
    swap(prv, nxt);
  }
  ll res = 0;
  for (int k = 0; k < 4; ++k) {
    res = max(res, prv[C][k]);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> R >> C >> K;
  for (int i = 0; i < K; ++i) {
    int r, c, v;
    cin >> r >> c >> v;
    V[r][c] = v;
  }
  solve();
}