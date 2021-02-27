#include <bits/stdc++.h>
#define li2 1.04516378 // https://oeis.org/A069284
using namespace std;
typedef long long ll;
typedef long double ld;

ld ln(__int128 x) {
  return log((ld)x);
}

__int128 fact(__int128 x) {
  __int128 res = 1;
  for (__int128 i = 1; i <= x; ++i) {
    res *= i;
  }
  return res;
}

ld f(__int128 t) {
  ld res = ln(ln(t)) + ln(t);
  for (__int128 i = 2; i < 30; ++i) {
    res += powl(ln(t), i) / (i * fact(i));
  }
  return res;
}

ld g(__int128 x) {
  return x / ln(x);
}

int main() {
  vector<ll> X = {10, 100, 1000, 10'000, 1'000'000, 1'000'000'000};
  vector<ll> Pi = {4, 25, 168, 1229, 78498, 50847534};
  for (ll i = 0; i < X.size(); ++i) {
    printf("x=%lld, pi=%lld, f=%.2Lf, g=%.2Lf\n",
           X[i],
           Pi[i],
           f(X[i]) - li2,
           g(X[i]));
  }
}

// f(x) is closer to pi(x) than g(x)
// x=10, pi=4, f=4.40, g=4.34
// x=100, pi=25, f=28.36, g=21.71
// x=1000, pi=168, f=175.85, g=144.76
// x=10000, pi=1229, f=1244.49, g=1085.74
// x=1000000, pi=78498, f=78622.33, g=72382.41
// x=1000000000, pi=50847534, f=49818835.48, g=48254942.43