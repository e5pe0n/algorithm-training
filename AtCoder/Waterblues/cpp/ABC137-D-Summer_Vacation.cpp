#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
map<ll, vector<ll>> C;

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    C[a].push_back(b);
  }
  priority_queue<ll> q;
  ll res = 0;
  for (ll i = 1; i <= M; ++i) {
    for (auto v : C[i]) {
      q.push(v);
    }
    if (q.size()) {
      res += q.top();
      q.pop();
    }
  }
  printf("%lld\n", res);
}