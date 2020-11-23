#include <bits/stdc++.h>
#define MAX_R 3000
#define MAX_C 3000
#define MAX_K 200'000
using namespace std;
typedef long long ll;

ll R, C, K;
ll V[MAX_R + 1][MAX_C + 1];
ll _V[3];
ll dp[2][MAX_C + 1];

void chmax(ll nv) {
  if (nv >= _V[0]) {
    _V[2] = _V[1];
    _V[1] = _V[0];
    _V[0] = nv;
  } else if (nv >= _V[1]) {
    _V[2] = _V[1];
    _V[1] = nv;
  } else if (nv >= _V[2]) {
    _V[2] = nv;
  }
}

ll sum() {
  ll res = 0;
  for (int i = 0; i < 3; ++i) {
    res += _V[i];
  }
  return res;
}

void solve() {
  ll *prv = dp[0];
  ll *nxt = dp[1];
  for (int i = 1; i <= R; ++i) {
    memset(_V, 0, sizeof(_V));
    ll t = 0;
    for (int j = 1; j <= C; ++j) {
      chmax(V[i][j]);
      nxt[j] = t + sum();
      if (nxt[j] < prv[j] + V[i][j]) {
        nxt[j] = prv[j] + V[i][j];
        t = prv[j];
        memset(_V, 0, sizeof(_V));
        _V[0] = V[i][j];
      }
    }
    // printf("\n");
    // for (int j = 1; j <= C; ++j) {
    //   printf("%lld%c", prv[j], j == C ? '\n' : ' ');
    // }
    // for (int j = 1; j <= C; ++j) {
    //   printf("%lld%c", nxt[j], j == C ? '\n' : ' ');
    // }
    swap(prv, nxt);
  }
  printf("%lld\n", prv[C]);
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