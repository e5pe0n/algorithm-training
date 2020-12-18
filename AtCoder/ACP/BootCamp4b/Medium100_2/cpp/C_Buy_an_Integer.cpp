#include <bits/stdc++.h>
#define MAX_N 1'000'000'000
using namespace std;
typedef long long ll;

ll A, B, X;

void solve() {
  ll res = 0;
  if (A * MAX_N + B * 10 <= X) {
    printf("%d\n", MAX_N);
    return;
  }
  for (int i = 1; i <= 9; ++i) {
    string s;
    for (int j = 0; j < i; ++j) {
      s += '9';
    }
    ll n = stoll(s);
    ll x = X - B * i;
    if (x <= 0) {
      break;
    }
    res = max(res, min(n, x / A));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B >> X;
  solve();
}