#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll res = 2;
  for (ll i = 3; i <= 7; ++i) {
    res ^= i;
  }
  printf("%lld\n", res);
}