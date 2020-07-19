#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 50

typedef long long ll;

using namespace std;

ll comb(ll n, ll k) {
  ll w = min(n - k, k);
  if (n <= 1 || w == 0) {
    return 1;
  }
  ll a = n;
  for (int i = n - 1; i > n - w; --i) {
    a *= i;
  }
  ll b = 1;
  for (int i = 2; i <= w; ++i) {
    b *= i;
  }
  return a / b;
}

int main() {
  int N, P;
  cin >> N >> P;
  ll NO = 0;
  ll NE = 0;
  for (int i = 0; i < N; ++i) {
    int a = 0;
    cin >> a;
    if (a % 2 == 0) {
      ++NE;
    } else {
      ++NO;
    }
  }
  ll e = (ll)pow(2, NE);
  ll o = 0;
  for (int i = P; i <= NO; i += 2) {
    o += comb(NO, i);
  }
  ll res = e * o;
  if (P == 0) {
    res = o > 0 ? e * o : e;
  } else {
    res = e > 0 ? o * e : o;
  }
  printf("%lld\n", res);
}