#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  map<ll, ll> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  ll res = 0;
  ll max_a = 0;
  ll max_a2 = 0;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    ll a = it->first;
    ll c = it->second;
    if (c < 2) {
      continue;
    }
    if (c >= 4) {
      res = max(res, a * a);
    }
    if (max_a <= a) {
      max_a2 = max_a;
      max_a = a;
    } else if (max_a2 <= a) {
      max_a2 = a;
    }
  }
  res = max(res, max_a * max_a2);
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}