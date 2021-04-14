#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<vector<ll>, vector<ll>> pvv;
typedef pair<ll, ll> pll;

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
  ll n = 19;
  auto [crs, nrs] = gen_CRs_and_NRs(n);
  vector<pll> fst, snd;
  for (ll i = 0; i < nrs.size() - 1; ++i) {
    for (ll j = i + 1; j < nrs.size(); ++j) {
      auto it = find(crs.begin(), crs.end(), nrs[i] * nrs[j]);
      if (it != crs.end())
        fst.push_back({nrs[i], nrs[j]});
      else
        snd.push_back({nrs[i], nrs[j]});
    }
  }
  puts("fst");
  for (ll i = 0; i < fst.size(); ++i) {
    printf("(%lld, %lld)%c",
           fst[i].first,
           fst[i].second,
           i == fst.size() - 1 ? '\n' : ' ');
  }
  puts("snd");
  for (ll i = 0; i < snd.size(); ++i) {
    printf("(%lld, %lld)%c",
           snd[i].first,
           snd[i].second,
           i == snd.size() - 1 ? '\n' : ' ');
  }
}