#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y;

void solve() {
  ll res;
  if (x == y) {
    res = 0;
  } else if (x == -y) {
    res = 1;
  } else if (x * y < 0) {
    res = max(abs(x), abs(y)) - min(abs(x), abs(y)) + 1;
  } else if (x == 0) {
    if (y > 0) {
      res = y - x;
    } else {
      res = x - y + 1;
    }
  } else if (y == 0) {
    if (x > 0) {
      res = x - y + 1;
    } else {
      res = y - x;
    }
  } else {
    if (x < y) {
      res = y - x;
    } else {
      res = x - y + 2;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> x >> y;
  solve();
}