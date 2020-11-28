#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve() {
  ll lb = 0;
  ll ub = 2'000'000'000;
  while (ub - lb > 1) {
    ll md = (lb + ub) / 2;
    if (md * (md + 1) / 2 <= n + 1) {
      lb = md;
    } else {
      ub = md;
    }
  }
  printf("%lld\n", n - lb + 1);
}

int main() {
  cin >> n;
  solve();
}