#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> gen_carmichaels(ll k) {
  vector<ll> res;
  for (ll i = 1; i <= k; ++i) {
    ll p1 = 6 * i + 1;
    ll p2 = 12 * i + 1;
    ll p3 = 18 * i + 1;
    res.push_back(p1 * p2 * p3);
  }
  return res;
}

int main() {
  vector<ll> cs = gen_carmichaels(5);
  for (auto v : cs) {
    printf("%lld\n", v);
  }
}
// 1729
// 12025
// 38665
// 89425
// 172081