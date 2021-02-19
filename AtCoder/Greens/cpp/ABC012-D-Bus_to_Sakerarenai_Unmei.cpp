#include <bits/stdc++.h>
#define MAX_N 300
#define MAX_M 44850
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll N, M;
ll d[MAX_N][MAX_N];

void warshall_floyd() {
  for (ll k = 0; k < N; ++k) {
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < N; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = INF;
    }
  }
  for (ll i = 0; i < M; ++i) {
    ll a, b, t;
    cin >> a >> b >> t;
    --a;
    --b;
    d[a][b] = t;
    d[b][a] = t;
  }
  warshall_floyd();
  ll res = INF;
  for (ll i = 0; i < N; ++i) {
    ll worst = 0;
    for (ll j = 0; j < N; ++j) {
      if (i != j) worst = max(worst, d[i][j]);
    }
    res = min(res, worst);
  }
  printf("%lld\n", res);
}