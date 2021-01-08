#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll X[MAX_N], Y[MAX_N];
vector<pll> V;
bool used[MAX_N];

void solve() {
  for (ll i = 0; i < N; ++i) {
    V.push_back({X[i], Y[i]});
  }
  sort(V.begin(), V.end());
  ll res = N;
  for (ll i = 0; i < N - 1; ++i) {
    for (ll j = i + 1; j < N; ++j) {
      ll p = V[j].first - V[i].first;
      ll q = V[j].second - V[i].second;
      ll cnt = 0;
      fill(used, used + N, false);
      while (true) {
        ll idx = 0;
        for (; idx < N; ++idx) {
          if (!used[idx]) { break; }
        }
        if (idx >= N) { break; }
        ++cnt;
        ll x = V[idx].first;
        ll y = V[idx].second;
        used[idx] = true;
        for (ll k = idx + 1; k < N; ++k) {
          if (!used[k] && x + p == V[k].first && y + q == V[k].second) {
            used[k] = true;
            x += p;
            y += q;
          }
        }
      }
      res = min(res, cnt);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  solve();
}