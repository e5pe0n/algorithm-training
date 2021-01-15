#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'000
#define MAX_N 100'000
#define MAX_Q 100'000
using namespace std;
typedef long long ll;

struct Edge {
  ll u, v, w;
};

ll N;
ll A[MAX_N], B[MAX_N], C[MAX_N];
ll Q, K;
ll X[MAX_Q], Y[MAX_Q];

vector<Edge> G[MAX_N];
ll d[MAX_N];

void bfs() {
  fill(d, d + N, INF);
  d[K] = 0;
  queue<ll> q;
  q.push(K);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto e : G[u]) {
      if (d[e.v] > d[u] + e.w) {
        d[e.v] = d[u] + e.w;
        q.push(e.v);
      }
    }
  }
}

void solve() {
  for (ll i = 0; i < N - 1; ++i) {
    G[A[i]].push_back(Edge{A[i], B[i], C[i]});
    G[B[i]].push_back(Edge{B[i], A[i], C[i]});
  }
  bfs();
  for (ll i = 0; i < Q; ++i) {
    printf("%lld\n", d[X[i]] + d[Y[i]]);
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i];
    --B[i];
  }
  cin >> Q >> K;
  --K;
  for (ll i = 0; i < Q; ++i) {
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }
  solve();
}