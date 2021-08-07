#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;

int main() {
  cin >> a >> b >> c;
  ll r = 1;
  for (ll i = 0; i < b; ++i) {
    r *= c;
  }
  if (a < r)
    puts("Yes");
  else
    puts("No");
}