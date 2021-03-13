#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll A, B, W;

int main() {
  cin >> A >> B >> W;
  W *= 1000;
  ll ma = 0, mi = INF;
  for (ll i = 1; i <= W / A; ++i) {
    double w = (double)W / i;
    if (A <= w && w <= B) {
      ma = max(ma, i);
      mi = min(mi, i);
    }
  }
  if (ma == 0)
    puts("UNSATISFIABLE");
  else
    printf("%lld %lld\n", mi, ma);
}