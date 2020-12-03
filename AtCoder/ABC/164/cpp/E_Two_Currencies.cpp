#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'000
#define MAX_N 50
#define MAX_M 100
using namespace std;
typedef long long ll;

struct Edge {
  ll u, v, a, b;
};

ll N, M, S;
ll U[MAX_M], V[MAX_M], A[MAX_M], B[MAX_M];
ll C[MAX_N], D[MAX_N];

vector<Edge> G[MAX_N];
ll cost[MAX_N][MAX_N];
map<ll, ll> t[MAX_N];

void add_edge(int u, int v, int a, int b) {
  G[u].push_back(Edge{u, v, a, b});
  G[v].push_back(Edge{v, u, a, b});
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto e : G[u]) {
      if (cost[s][e.v] > cost[s][u] + e.a) {
        cost[s][e.v] = cost[s][u] + e.a;
        q.push(e.v);
      }
    }
  }
}

void bfs2(int s) {
  // priority_queue<pll, vector<pll>, greater<vector<pll>::value_type>> q;
  queue<vector<ll>> q;
  q.push(vector<ll>{0, s, S});
  while (!q.empty()) {
    vector<ll> v = q.front();
    ll d = v[0];
    ll u = v[1];
    ll _s = v[2];
    q.pop();
    for (int v = 0; v < N; ++v) {
      t[u][cost[u][v]] = min(t[u][cost[u][v]], d + (ll)ceil(max(cost[u][v] - _s, 0LL) / C[u]) * D[u]);
    }
    for (auto e : G[u]) {
      for (auto p : t[u]) {
        if (t[e.v][p.first - e.a] > p.second + e.b) {
          t[e.v][p.first - e.a] = p.second + e.b;
          q.push(vector<ll>{p.second + e.b, e.v, max(0LL, _s - e.a)});
        }
      }
    }
  }
}

void solve() {
  for (int i = 0; i < M; ++i) {
    add_edge(U[i], V[i], A[i], B[i]);
  }

  for (int i = 0; i < N; ++i) {
    fill(cost[i], cost[i] + N, INF);
    cost[i][i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    bfs(i);
  }
  for (int i = 0; i < N; ++i) {
    for (int u = 0; u < N; ++u) {
      for (int v = 0; v < N; ++v) {
        t[i][cost[u][v]] = INF;
      }
    }
  }
  bfs2(0);
  for (int i = 1; i < N; ++i) {
    printf("%lld\n", t[i][0]);
  }
}

int main() {
  cin >> N >> M >> S;
  for (int i = 0; i < M; ++i) {
    cin >> U[i] >> V[i] >> A[i] >> B[i];
    --U[i];
    --V[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> C[i] >> D[i];
  }
  solve();
}