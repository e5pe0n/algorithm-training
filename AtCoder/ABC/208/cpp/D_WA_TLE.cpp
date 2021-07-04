#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 400;
const ll MAX_M = MAX_N * (MAX_N - 1);
const ll INF = 1e9;

struct Edge {
  ll u, v, w;
};

ll N, M;
vector<Edge> G[MAX_N];

ll dist[MAX_N][MAX_N];
ll res[MAX_N][MAX_N][MAX_N];
ll D[MAX_N][MAX_N];

void init(ll s) {
  for (ll j = 0; j < N; ++j) {
    for (ll k = 0; k < N; ++k) {
      dist[j][k] = j == s ? 0 : INF;
    }
  }
}

void bfs(ll s, ll t) {
  init(s);
  queue<vector<ll>> q;
  q.push({s, 0, s});
  while (q.size()) {
    auto vec = q.front();
    ll u = vec[0];
    ll d = vec[1];
    ll k = vec[2];
    q.pop();
    for (auto e : G[u]) {
      if (dist[e.v][k] > d + e.w) {
        dist[e.v][k] = d + e.w;
        q.push({e.v, d + e.w, max(e.v, k)});
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      D[i][j] = i == j ? 0 : INF;
    }
  }
  for (ll i = 0; i < M; ++i) {
    ll A, B, C;
    cin >> A >> B >> C;
    --A, --B;
    G[A].push_back(Edge{A, B, C});
    D[A][B] = C;
  }
  ll res = 0;
  for (ll s = 0; s < N; ++s) {
    for (ll t = 0; t < N; ++t) {
      bfs(s, t);
      ll prv = D[s][t];
      for (ll k = 0; k < N; ++k) {
        // printf("s=%lld, t=%lld, k=%lld, ", s, t, k);
        if (dist[t][k] < INF) {
          prv = min(prv, dist[t][k]);
          res += prv;
          // printf("d=%lld\n", prv);
        } else if (prv < INF) {
          res += prv;
          // printf("d=%lld\n", prv);
        } else {
          // puts("d=0");
        }
      }
    }
  }
  printf("%lld\n", res);
}