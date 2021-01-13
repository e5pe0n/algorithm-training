#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    ++C[A[i]];
  }
  ll cnt = 0;
  for (auto p : C) {
    if (p.second % 2 == 0) ++cnt;
  }
  ll res = C.size() - (cnt % 2 != 0);
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}