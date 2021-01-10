#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll res = 0;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0 && N / i - 1 > i) res += N / i - 1;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}