#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, u, v;
vector<ll> G[MAX_N];
ll d1[MAX_N];
ll d2[MAX_N];

void bfs(ll s, ll *d) {
  fill(d, d + N, MAX_N);
  d[s] = 0;
  queue<ll> q;
  q.push(s);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N >> u >> v;
  --u;
  --v;
  for (ll i = 0; i < N - 1; ++i) {
    ll A, B;
    cin >> A >> B;
    --A;
    --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  bfs(u, d1);
  bfs(v, d2);
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (d1[i] < d2[i]) res = max(res, d2[i] - 1);
  }
  ll res2 = MAX_N;
  for (ll i = 0; i < N; ++i) {
    if (d1[i] == d2[i]) res2 = min(res2, d1[i]);
  }
  if (res2 != MAX_N && res < res2) res = res2;
  printf("%lld\n", res);
}