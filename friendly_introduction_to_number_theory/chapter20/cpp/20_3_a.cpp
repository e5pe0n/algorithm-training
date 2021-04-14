#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<vector<ll>, vector<ll>> pvv;

pvv gen_CRs_and_NRs(ll n) {
  ll b = 0;
  for (ll i = 0; i < n; ++i) {
    b |= 1 << (i * i * i % n);
  }
  vector<ll> crs, nrs;
  for (ll i = 0; i < n; ++i) {
    if (b & (1 << i))
      crs.push_back(i);
    else
      nrs.push_back(i);
  }
  return {crs, nrs};
}

int main() {
  vector<ll> ps{5, 7, 11, 13, 19};
  for (auto p : ps) {
    printf("p=%lld\n", p);
    auto [crs, nrs] = gen_CRs_and_NRs(p);
    printf("CRs: ");
    for (auto cr : crs)
      printf("%lld ", cr);
    printf("\nNRs: ");
    for (auto nr : nrs)
      printf("%lld ", nr);
    puts("\n");
  }
}