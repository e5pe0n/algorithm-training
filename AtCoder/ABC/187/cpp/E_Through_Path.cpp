#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<ll> G[MAX_N];
pll E[MAX_N];
ll Q;

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
    E[i] = {a, b};
  }
  vector<ll> stk{0};
  vector<ll> depth(N, -1);
  depth[0] = 0;
  while (!stk.empty()) {
    ll u = stk.back();
    stk.pop_back();
    for (auto v : G[u]) {
      if (depth[v] < 0) {
        depth[v] = depth[u] + 1;
        stk.push_back(v);
      }
    }
  }
  vector<ll> sum(N, 0);
  cin >> Q;
  for (int _ = 0; _ < Q; ++_) {
    ll t, e, x;
    cin >> t >> e >> x;
    --e;
    ll a, b;
    tie(a, b) = E[e];
    if (depth[a] > depth[b]) {
      swap(a, b);
      t ^= 3;
    }
    if (t == 1) {
      sum[0] += x;
      sum[b] -= x;
    } else {
      sum[b] += x;
    }
  }
  stk = {0};
  while (!stk.empty()) {
    ll u = stk.back();
    stk.pop_back();
    for (auto v : G[u]) {
      if (depth[u] < depth[v]) {
        sum[v] += sum[u];
        stk.push_back(v);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld\n", sum[i]);
  }
}