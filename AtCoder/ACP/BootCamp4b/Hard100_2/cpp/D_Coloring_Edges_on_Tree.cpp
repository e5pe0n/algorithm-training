#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {
  ll u, v, idx;
};

ll N, K;
ll A[MAX_N], B[MAX_N];
vector<Edge> G[MAX_N];
ll res[MAX_N];

void bfs() {
  fill(res, res + N, -1);
  queue<pll> q;
  q.push({0, K});
  while (q.size()) {
    auto [u, c] = q.front();
    q.pop();
    ll cnt = 0;
    for (ll i = 0; i < G[u].size(); ++i) {
      auto e = G[u][i];
      if (res[e.idx] < 0) {
        res[e.idx] = cnt + (cnt >= c);
        ++cnt;
        q.push({e.v, res[e.idx]});
      }
    }
  }
}

void solve() {
  for (ll i = 0; i < N - 1; ++i) {
    G[A[i]].push_back(Edge{A[i], B[i], i});
    G[B[i]].push_back(Edge{B[i], A[i], i});
  }
  K = 0;
  for (ll i = 0; i < N; ++i) {
    K = max(K, (ll)G[i].size());
  }
  bfs();
  printf("%lld\n", K);
  for (ll i = 0; i < N - 1; ++i) {
    printf("%lld\n", res[i] + 1);
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}