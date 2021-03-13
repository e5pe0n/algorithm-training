#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  string NS = to_string(N);
  ll a = NS.size() / 3;
  ll b = NS.size() % 3;
  ll res = 0;
  ll ub = 1000;
  ll lb = 1;
  if (b == 0) {
    for (ll i = 0; i < a; ++i) {
      if (i == a - 1)
        res += (N - lb + 1) * i;
      else {
        res += i * (ub - lb);
        lb = ub;
        ub *= 1000;
      }
    }
  } else {
    for (ll i = 0; i < a; ++i) {
      res += i * (ub - lb);
      lb = ub;
      ub *= 1000;
    }
    res += (N - lb + 1) * a;
  }
  printf("%lld\n", res);
}