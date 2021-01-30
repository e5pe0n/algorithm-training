#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  while (N % 2 == 0) {
    N /= 2;
  }
  ll res = 0;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ++res;
      if (N / i != i) ++res;
    }
  }
  printf("%lld\n", res * 2);
}

int main() {
  cin >> N;
  solve();
}