#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 100'000
#define MAX_M 100'000
#define MAX_K 17
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M], B[MAX_M];
ll K;
ll C[MAX_K];
vector<ll> G[MAX_N];

ll dp[1 << MAX_K][MAX_K];
ll dist[MAX_K][MAX_K];
ll d[MAX_N];

void bfs(ll s) {
  fill(d, d + N, INF);
  d[C[s]] = 0;
  queue<ll> q;
  q.push(C[s]);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  for (ll i = 0; i < K; ++i) {
    dist[s][i] = d[C[i]];
  }
}

void solve() {
  for (ll i = 0; i < M; ++i) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  for (ll i = 0; i < K; ++i) {
    bfs(i);
  }
  for (ll i = 0; i < 1 << K; ++i) {
    fill(dp[i], dp[i] + K, INF);
  }
  for (ll k = 0; k < K; ++k) {
    dp[1 << k][k] = 1;
  }
  for (ll S = 1; S < (1 << K); ++S) {
    for (ll u = 0; u < K; ++u) {
      if (!(S & (1 << u))) continue;
      for (ll v = 0; v < K; ++v) {
        if (S & (1 << v)) continue;
        dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u] + dist[u][v]);
      }
    }
  }
  ll res = *min_element(dp[(1 << K) - 1], dp[(1 << K) - 1] + K);
  if (res == INF) res = -1;
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  cin >> K;
  for (ll i = 0; i < K; ++i) {
    cin >> C[i];
    --C[i];
  }
  solve();
}