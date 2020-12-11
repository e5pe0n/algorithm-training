#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H;

void solve() {
  ll x = 1;
  ll res = 0;
  while (H > 0) {
    res += x;
    H /= 2;
    x *= 2;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> H;
  solve();
}