#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

struct Edge {
  ll u, v, w;
};

ll N;
ll U[MAX_N], V[MAX_N], W[MAX_N];
vector<Edge> G[MAX_N];
ll res[MAX_N];

void bfs() {
  fill(res, res + N, -1);
  res[0] = 0;
  queue<ll> q;
  q.push(0);
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (auto e : G[u]) {
      if (res[e.v] < 0) {
        res[e.v] = (res[u] + e.w) % 2;
        q.push(e.v);
      }
    }
  }
}

void solve() {
  for (ll i = 0; i < N - 1; ++i) {
    G[U[i]].push_back(Edge{U[i], V[i], W[i]});
    G[V[i]].push_back(Edge{V[i], U[i], W[i]});
  }
  bfs();
  for (ll i = 0; i < N; ++i) {
    printf("%lld\n", res[i]);
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> U[i] >> V[i] >> W[i];
    --U[i];
    --V[i];
  }
  solve();
}