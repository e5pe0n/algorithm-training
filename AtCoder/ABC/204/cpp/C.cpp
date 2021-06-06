#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 2000;
const ll MAX_M = 2000;

ll N, M;
ll A[MAX_M], B[MAX_M];
vector<ll> G[MAX_N];
bool used[MAX_N];

void bfs(ll s) {
  used[s] = true;
  queue<ll> q;
  q.push(s);
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (!used[v]) {
        used[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    ll A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
  }
  ll res = 0;
  for (ll u = 0; u < N; ++u) {
    for (ll i = 0; i < N; ++i) {
      used[i] = false;
    }
    bfs(u);
    for (ll v = 0; v < N; ++v) {
      res += used[v];
    }
  }
  cout << res << endl;
}