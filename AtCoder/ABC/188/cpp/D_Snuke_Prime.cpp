#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;
typedef long long ll;

ll N, C;
ll a[MAX_N], b[MAX_N], c[MAX_N];

void solve() {
  map<ll, vector<ll>> A;
  map<ll, vector<ll>> B;
  for (ll i = 0; i < N; ++i) {
    A[a[i]].push_back(i);
    B[b[i] + 1].push_back(i);
  }
  set<ll> events;
  for (auto p : A) {
    events.insert(p.first);
  }
  for (auto p : B) {
    events.insert(p.first);
  }
  ll prv = 0;
  ll t = 0;
  ll res = 0;
  for (auto e : events) {
    res += min(C, t) * (e - prv);
    for (auto v : A[e]) {
      t += c[v];
    }
    for (auto v : B[e]) {
      t -= c[v];
    }
    prv = e;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> C;
  for (ll i = 0; i < N; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  solve();
}