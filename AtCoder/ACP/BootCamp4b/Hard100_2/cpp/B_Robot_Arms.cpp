#include <bits/stdc++.h>
#define MAX_N 100'000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll X[MAX_N], L[MAX_N];

void solve() {
  vector<pll> V;
  for (int i = 0; i < N; ++i) {
    V.push_back({X[i] + L[i], X[i] - L[i]});
  }
  sort(V.begin(), V.end());
  ll res = 0;
  ll t = -INF;
  for (int i = 0; i < N; ++i) {
    pll v = V[i];
    if (t <= v.second) {
      t = v.first;
      ++res;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> L[i];
  }
  solve();
}