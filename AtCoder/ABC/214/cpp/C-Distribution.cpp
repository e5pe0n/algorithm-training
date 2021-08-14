#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 200'000;
const ll MAX_T = 1'000'000'000;
const ll INF = 1e18;
ll N;
ll S[MAX_N], T[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> T[i];
  }
  ll min_i = 0;
  ll min_t = T[0];
  for (ll i = 0; i < N; ++i) {
    if (min_t > T[i]) {
      min_t = T[i];
      min_i = i;
    }
  }
  ll t = INF;
  vector<ll> res(N, INF);
  for (ll i = 0; i < N; ++i) {
    ll j = (i + min_i) % N;
    t = min(t, T[j]);
    res[j] = min(res[j], t);
    t += S[j];
  }
  for (auto r : res)
    printf("%lld\n", r);
}