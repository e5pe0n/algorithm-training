#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll N, K;

ll com(ll n, ll k) {
  if (n <= 0 || k > n) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }
  ll x = n;
  for (ll i = n - 1; i > n - k; --i) {
    x *= i;
  }
  ll y = k;
  for (ll i = k - 1; i > 0; --i) {
    y *= i;
  }
  return x / y;
}

ll p(ll x, ll n) { return (ll)pow(x, n); }

ll rec(ll i, ll k, bool smaller) {
  if (i == N) {
    return k == 0;
  }
  if (k == 0) {
    return 1;
  }
  if (smaller) {
    return com(N - i, k) * p(9, k);
  } else {
    if (S[i] == '0') {
      return rec(i + 1, k, false);
    } else {
      ll zero = rec(i + 1, k, true);
      ll md = rec(i + 1, k - 1, true) * (S[i] - '1');
      ll ub = rec(i + 1, k - 1, false);
      return zero + md + ub;
    }
  }
}

void solve() {
  N = S.size();
  printf("%lld\n", rec(0, K, false));
}

int main() {
  cin >> S >> K;
  solve();
}