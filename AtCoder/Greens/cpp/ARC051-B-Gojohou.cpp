#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;

int main() {
  cin >> K;
  ll a = 1, b = 0;
  while (K-- >= 0) {
    ll r = b;
    b = a;
    a = b + r;
  }
  printf("%lld %lld\n", a, b);
}