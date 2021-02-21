#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll B, C;

pll extract(ll _B, ll _C) {
  ll n = _C / 2;
  if (_C % 2)
    return {-_B - n, -_B + n};
  else {
    if (!_C) return {_B, _B};
    return {_B - n, _B + n - 1};
  }
}

int main() {
  cin >> B >> C;
  auto [a, b] = extract(B, C);
  auto [c, d] = extract(B, C - 1);
  ll res = (b - a + 1) + (d - c + 1) - max(0LL, min(b, d) - max(a, c) + 1);
  printf("%lld\n", res);
}