#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

ll com(ll n, ll k) {
  if (n < 0 || k < 0 || k > n) return 0;
  if (k == 0) return 1;
  ll res = 1;
  for (ll i = 1; i <= k; ++i) {
    res = res * (n - i + 1) / i;
  }
  return res;
}

void solve() {
  printf("6C2=%lld\n", com(6, 2)); // 15
  printf("6C0=%lld\n", com(6, 0)); // 1
  printf("6C8=%lld\n", com(6, 8)); // 0
}

int main() {
  cin >> N;
  solve();
}