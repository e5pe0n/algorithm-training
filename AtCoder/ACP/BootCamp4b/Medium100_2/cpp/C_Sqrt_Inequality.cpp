#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

void solve() {
  ll x = c - a - b;
  if (x > 0 && 4 * a * b < x * x) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> a >> b >> c;
  solve();
}