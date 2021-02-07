#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 2000
#define MAX_M 2000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {
  ll u, v, weight;
};

ll N, M;
ll A[MAX_M], B[MAX_M], C[MAX_M];
vector<Edge> G1[MAX_N];
vector<Edge> G2[MAX_N];
ll d1[MAX_N];
ll d2[MAX_N];

void init(ll s, ll *d) {
  fill(d, d + N, INF);
  d[s] = 0;
}

void dijkstra(ll s, ll *d, vector<Edge> *G) {
  init(s, d);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});
  while (q.size()) {
    auto [_d, u] = q.top();
    q.pop();
    if (d[u] < _d) continue;
    for (auto e : G[u]) {
      if (d[e.v] > d[u] + e.weight) {
        d[e.v] = d[u] + e.weight;
        q.push({d[e.v], e.v});
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i];
    --B[i];
    G1[A[i]].push_back(Edge{A[i], B[i], C[i]});
    G2[B[i]].push_back(Edge{B[i], A[i], C[i]});
  }
  for (ll i = 0; i < N; ++i) {
    ll res = INF;
    for (ll j = 0; j < M; ++j) {
      if (A[j] == i && B[j] == i) { res = min(res, C[j]); }
    }
    dijkstra(i, d1, G1);
    dijkstra(i, d2, G2);
    for (ll j = 0; j < N; ++j) {
      if (i != j) res = min(res, d1[j] + d2[j]);
    }
    if (res == INF) res = -1;
    printf("%lld\n", res);
  }
}