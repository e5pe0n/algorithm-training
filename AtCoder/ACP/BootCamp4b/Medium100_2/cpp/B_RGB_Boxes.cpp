#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll R, G, B, N;

void solve() {
  ll NR = N / R;
  ll NG = N / G;
  ll res = 0;
  for (int i = 0; i <= NR; ++i) {
    for (int j = 0; j <= NG; ++j) {
      ll n = N - R * i - G * j;
      if (n >= 0 && n % B == 0) {
        ++res;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> R >> G >> B >> N;
  solve();
}