#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K, A, B;

void solve() {
  ll res;
  if (K <= A - 1 || B <= A) {
    res = K + 1;
  } else {
    ll k = K - (A - 1);
    res = max(K + 1, A + (B - A) * (k / 2) + k % 2);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> K >> A >> B;
  solve();
}