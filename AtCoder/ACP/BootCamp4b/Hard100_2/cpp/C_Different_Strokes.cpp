#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  vector<pll> V;
  for (ll i = 0; i < N; ++i) {
    V.push_back({A[i], B[i]});
  }
  auto cmp = [](const pll &p1, const pll &p2) {
    return (p1.first + p1.second) > (p2.first + p2.second);
  };
  sort(V.begin(), V.end(), cmp);
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      res += V[i].first;
    } else {
      res -= V[i].second;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}