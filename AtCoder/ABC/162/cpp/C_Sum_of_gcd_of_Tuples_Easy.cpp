#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;

void solve() {
  ll res = 0;
  for (int a = 1; a <= K; ++a) {
    for (int b = 1; b <= K; ++b) {
      for (int c = 1; c <= K; ++c) {
        res += __gcd(a, __gcd(b, c));
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> K;
  solve();
}