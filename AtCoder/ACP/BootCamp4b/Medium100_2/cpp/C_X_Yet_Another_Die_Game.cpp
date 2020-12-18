#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X;

void solve() {
  ll p = X / 11;
  ll q = X % 11;
  q = (q + 6 - 1) / 6;
  printf("%lld\n", p * 2 + q);
}

int main() {
  cin >> X;
  solve();
}