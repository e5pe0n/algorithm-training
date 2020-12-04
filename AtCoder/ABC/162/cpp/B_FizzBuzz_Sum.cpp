#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll res = 0;
  for (ll i = 1; i <= N; ++i) {
    if (i % 3 != 0 && i % 5 != 0) {
      res += i;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}