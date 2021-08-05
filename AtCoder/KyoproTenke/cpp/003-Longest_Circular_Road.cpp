#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
const ll INF = 1e18;
ll N;
vector<ll> G[MAX_N];
ll dist[MAX_N];

void init() {
  fill(dist, dist + N, INF);
}

void bfs(ll s) {
  init();
  dist[s] = 0;
  queue<ll> q;
  q.push(s);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(0);
  ll max_d = 0;
  ll s = 0;
  for (ll i = 0; i < N; ++i) {
    if (max_d < dist[i]) {
      max_d = dist[i];
      s = i;
    }
  }
  bfs(s);
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res = max(res, dist[i]);
  }
  printf("%lld\n", res + 1);
}