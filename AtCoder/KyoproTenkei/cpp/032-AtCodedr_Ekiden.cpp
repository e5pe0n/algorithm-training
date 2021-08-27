#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 10;
const ll MAX_A = 1000;
const ll INF = 1 << 22;
ll N;
ll A[MAX_N][MAX_N];
const ll MAX_M = 100;
ll M;
bool R[MAX_N][MAX_N];
bool used[MAX_N];

ll dfs(ll u, ll k, ll t) {
  if (k == N) return t;
  ll res = INF;
  for (ll v = 0; v < N; ++v) {
    if (!used[v] && !R[u][v]) {
      used[v] = true;
      res = min(res, dfs(v, k + 1, t + A[v][k]));
      used[v] = false;
    }
  }
  return res;
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  cin >> M;
  for (ll i = 0; i < M; ++i) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    R[x][y] = R[y][x] = true;
  }
  ll res = INF;
  for (ll u = 0; u < N; ++u) {
    used[u] = true;
    res = min(res, dfs(u, 1, A[u][0]));
    used[u] = false;
  }
  if (res == INF) res = -1;
  printf("%lld\n", res);
}