#include <bits/stdc++.h>
#define MAX_M 100'000
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll P[MAX_M];
string S[MAX_M];

void solve() {
  map<ll, pll> C;
  for (ll i = 0; i < M; ++i) {
    auto p = C[P[i]];
    if (p.first == 0) {
      if (S[i] == "AC")
        ++C[P[i]].first;
      else
        ++C[P[i]].second;
    }
  }
  ll AC = 0;
  ll WA = 0;
  for (auto p : C) {
    auto _p = p.second;
    if (_p.first > 0) {
      ++AC;
      WA += _p.second;
    }
  }
  printf("%lld %lld\n", AC, WA);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> P[i] >> S[i];
  }
  solve();
}