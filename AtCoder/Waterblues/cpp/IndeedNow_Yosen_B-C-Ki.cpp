#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
vector<ll> G[MAX_N];
bool used[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  fill(used, used + N, false);
  vector<ll> res;
  priority_queue<ll, vector<ll>, greater<vector<ll>::value_type>> q;
  q.push(0);
  while (!q.empty()) {
    ll u = q.top();
    q.pop();
    if (used[u]) continue;
    used[u] = true;
    res.push_back(u);
    for (auto v : G[u]) {
      if (!used[v]) q.push(v);
    }
  }
  for (auto it = res.begin(); it != res.end(); ++it) {
    printf("%lld%c", *it + 1, it == --res.end() ? '\n' : ' ');
  }
}