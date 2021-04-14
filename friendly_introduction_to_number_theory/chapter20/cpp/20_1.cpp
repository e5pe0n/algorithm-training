#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll b = 0;
  for (ll i = 0; i < 19; ++i) {
    b |= 1 << (i * i % 19);
  }
  printf("QRs: ");
  for (ll i = 0; i < 19; ++i) {
    if (b & (1 << i)) printf("%lld ", i);
  }
  printf("\nNRs: ");
  for (ll i = 0; i < 19; ++i) {
    if (!(b & (1 << i))) printf("%lld ", i);
  }
  puts("");
}

// QRs: 0 1 4 5 6 7 9 11 16 17
// NRs: 2 3 8 10 12 13 14 15 18