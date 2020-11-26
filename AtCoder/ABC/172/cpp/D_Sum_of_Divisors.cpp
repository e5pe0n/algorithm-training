#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

void solve() {
  ll res = 0;
  for (ll i = 1; i <= N; ++i) {
    res += (N / i) * (N / i + 1) * i / 2;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}