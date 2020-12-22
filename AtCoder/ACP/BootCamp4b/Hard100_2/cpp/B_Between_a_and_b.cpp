#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, x;

void solve() {
  ll cnt_b = b / x;
  ll cnt_a = max(0LL, a - 1) / x;
  printf("%lld\n", cnt_b - cnt_a + (a == 0));
}

int main() {
  cin >> a >> b >> x;
  solve();
}