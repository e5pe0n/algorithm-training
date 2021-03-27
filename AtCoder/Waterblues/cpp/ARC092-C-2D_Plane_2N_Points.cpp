#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;

int main() {
  cin >> N;
  vector<pll> R;
  for (ll i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    R.push_back({a, b});
  }
  vector<pll> B;
  for (ll i = 0; i < N; ++i) {
    ll c, d;
    cin >> c >> d;
    B.push_back({c, d});
  }
  auto cmpB = [](const pll &p1, const pll &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
  };
  sort(B.begin(), B.end(), cmpB);
  vector<bool> used(N, false);
  for (ll i = 0; i < N; ++i) {
    ll _j = -1;
    ll _x = -1;
    for (ll j = 0; j < N; ++j) {
      if (!used[j] && R[j].second < B[i].second && R[j].first < B[i].first) {
        if (R[j].first > _x) {
          _j = j;
          _x = R[j].first;
        }
      }
    }
    if (_j >= 0) used[_j] = true;
  }
  ll res = 0;
  for (auto v : used)
    res += v;
  printf("%lld\n", res);
}