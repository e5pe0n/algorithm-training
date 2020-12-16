#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X;

void solve() {
  ll lb = 0;
  ll ub = X;
  while (ub - lb > 1) {
    ll md = (ub + lb) / 2;
    if (md * (md + 1) / 2 >= X) {
      ub = md;
    } else {
      lb = md;
    }
  }
  printf("%lld\n", ub);
}

int main() {
  cin >> X;
  solve();
}