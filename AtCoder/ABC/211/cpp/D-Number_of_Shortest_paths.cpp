#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1'000'000'007;
const ll MAX_N = 200'000;
const ll MAX_M = 200'000;

ll N, M;
vector<ll> G[MAX_N];
ll D[MAX_N];
ll C[MAX_N];

void bfs() {
  fill(D, D + N, INF);
  D[0] = 0;
  C[0] = 1;
  queue<ll> q;
  q.push(0);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (D[v] == D[u] + 1) {
        C[v] = (C[v] + C[u]) % MOD;
      } else if (D[v] > D[u] + 1) {
        C[v] = C[u];
        D[v] = D[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs();
  printf("%lld\n", C[N - 1]);
}