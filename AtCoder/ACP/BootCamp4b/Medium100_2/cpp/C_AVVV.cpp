#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll V[MAX_N];

void solve() {
  map<ll, ll> C1;
  map<ll, ll> C2;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      ++C1[V[i]];
    } else {
      ++C2[V[i]];
    }
  }
  if (C1.size() == 1 && C2.size() == 1 && C1.begin()->first == C2.begin()->first) {
    printf("%lld\n", N / 2);
    return;
  }
  vector<pll> V1;
  for (auto p : C1) {
    V1.push_back({p.second, p.first});
  }
  vector<pll> V2;
  for (auto p : C2) {
    V2.push_back({p.second, p.first});
  }
  sort(V1.rbegin(), V1.rend());
  sort(V2.rbegin(), V2.rend());
  int i1 = 0;
  int i2 = 0;
  ll res = N;
  if (V1[i1].second == V2[i2].second) {
    res = min(res, N / 2 - V1[i1].first + N / 2 - V2[i2 + 1].first);
    res = min(res, N / 2 - V1[i1 + 1].first + N / 2 - V2[i2].first);
  } else {
    res = N / 2 - V1[i1].first + N / 2 - V2[i2].first;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> V[i];
  }
  solve();
}