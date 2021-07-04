#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MAX_N = 400;
const ll MAX_M = MAX_N * (MAX_N - 1);

ll N, M;
vector<vector<ll>> d(MAX_N, vector<ll>(MAX_N, INF));

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    d[i][i] = 0;
  }
  for (ll i = 0; i < M; ++i) {
    ll A, B, C;
    cin >> A >> B >> C;
    d[A - 1][B - 1] = C;
  }
  ll res = 0;
  for (ll k = 0; k < N; ++k) {
    vector<vector<ll>> nxt(N, vector<ll>(N));
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < N; ++j) {
        nxt[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if (nxt[i][j] < INF) res += nxt[i][j];
      }
    }
    d = nxt;
  }
  printf("%lld\n", res);
}