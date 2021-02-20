#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {
  ll u, v, weight, k;
};

ll N, M, X, Y;
ll A[MAX_M], B[MAX_M], T[MAX_M], K[MAX_M];
vector<Edge> G[MAX_N];
ll dist[MAX_N];

void init(ll s) {
  fill(dist, dist + N, INF);
  dist[s] = 0;
}

void dijkstra(ll s) {
  init(s);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] < d) continue;
    for (auto e : G[u]) {
      ll w = e.weight + (dist[u] + e.k - 1) / e.k * e.k;
      if (dist[e.v] > w) {
        dist[e.v] = w;
        q.push({dist[e.v], e.v});
      }
    }
  }
}

int main() {
  cin >> N >> M >> X >> Y;
  --X;
  --Y;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i] >> T[i] >> K[i];
    --A[i];
    --B[i];
    G[A[i]].push_back(Edge{A[i], B[i], T[i], K[i]});
    G[B[i]].push_back(Edge{B[i], A[i], T[i], K[i]});
  }
  dijkstra(X);
  ll res = dist[Y];
  if (res == INF) res = -1;
  printf("%lld\n", res);
  // for (ll i = 0; i < N; ++i) {
  //   printf("%lld%c", dist[i], i == N - 1 ? '\n' : ' ');
  // }
}