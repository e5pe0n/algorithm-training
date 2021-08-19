#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1 << 20;
const ll MAX_N = 100'000;
ll N;
vector<ll> G[MAX_N];
ll dist[MAX_N];
vector<ll> odd;
vector<ll> even;

void bfs() {
  queue<ll> q;
  q.push(0);
  even.push_back(0);
  fill(dist, dist + N, INF);
  dist[0] = 0;
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        if (dist[v] % 2 == 0)
          even.push_back(v);
        else
          odd.push_back(v);
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
  bfs();
  auto V = (odd.size() >= N / 2) ? odd : even;
  for (ll i = 0; i < N / 2; ++i) {
    printf("%lld%c", V[i] + 1, i == N / 2 - 1 ? '\n' : ' ');
  }
}