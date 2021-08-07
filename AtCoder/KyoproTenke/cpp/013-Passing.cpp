#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;
const ll MAX_N = 100'000;
const ll MAX_M = 100'000;

ll N, M;

struct Edge {
  ll u, v, w;
};

vector<Edge> G[MAX_N];
ll dist1[MAX_N];
ll dist2[MAX_N];

void init(ll s, ll *dist) {
  fill(dist, dist + N, INF);
  dist[s] = 0;
}

void dijkstra(ll s, ll *dist) {
  init(s, dist);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] < d) continue;
    for (auto e : G[u]) {
      if (dist[e.v] > dist[u] + e.w) {
        dist[e.v] = dist[u] + e.w;
        q.push({dist[e.v], e.v});
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    G[a].push_back(Edge{a, b, c});
    G[b].push_back(Edge{b, a, c});
  }
  dijkstra(0, dist1);
  dijkstra(N - 1, dist2);
  for (ll i = 0; i < N; ++i) {
    printf("%lld\n", dist1[i] + dist2[i]);
  }
}