#include <bits/stdc++.h>
#define MAX_A 10'000
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  ll M = 0;
  vector<ll> ps;
  vector<ll> ng;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] >= 0) ps.push_back(A[i]);
    if (A[i] < 0) ng.push_back(A[i]);
  }
  sort(ps.begin(), ps.end());
  sort(ng.rbegin(), ng.rend());
  vector<pll> res;
  if (ng.empty() || ps.empty()) {
    if (ng.empty()) {
      for (ll i = 0; i < ps.size() - 2; ++i) {
        res.push_back({ps[i], ps[i + 1]});
        ps[i + 1] = ps[i] - ps[i + 1];
      }
      res.push_back({ps[ps.size() - 1], ps[ps.size() - 2]});
      M = ps[ps.size() - 1] - ps[ps.size() - 2];
    } else {
      for (ll i = 1; i < ng.size(); ++i) {
        res.push_back({ng[0], ng[i]});
        ng[0] -= ng[i];
      }
      M = ng[0];
    }
  } else {
    for (ll i = 0; i < ps.size() - 1; ++i) {
      res.push_back({ng[0], ps[i]});
      ng[0] -= ps[i];
    }
    for (ll i = 0; i < ng.size(); ++i) {
      res.push_back({ps[ps.size() - 1], ng[i]});
      ps[ps.size() - 1] -= ng[i];
    }
    M = ps[ps.size() - 1];
  }
  printf("%lld\n", M);
  for (auto p : res)
    printf("%lld %lld\n", p.first, p.second);
}
