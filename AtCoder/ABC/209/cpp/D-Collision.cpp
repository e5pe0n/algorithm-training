#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;

ll N, Q;
vector<ll> G[MAX_N];
ll dist[MAX_N];

void bfs() {
  queue<ll> q;
  fill(dist, dist + N, -1);
  dist[0] = 0;
  q.push(0);
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N >> Q;
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs();
  while (Q--) {
    ll c, d;
    cin >> c >> d;
    --c, --d;
    if ((dist[c] - dist[d]) % 2 == 0) {
      puts("Town");
    } else {
      puts("Road");
    }
  }
}