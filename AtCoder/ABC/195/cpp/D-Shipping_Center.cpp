#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 50
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, Q;
vector<pll> WV;
ll X[MAX_M];

int main() {
  cin >> N >> M >> Q;
  WV = vector<pll>();
  for (ll i = 0; i < N; ++i) {
    ll W, V;
    cin >> W >> V;
    WV.push_back({W, V});
  }
  auto cmp = [](const pll &left, const pll &right) {
    if (left.second == right.second) return left.first < right.first;
    return left.second > right.second;
  };
  sort(WV.begin(), WV.end(), cmp);
  for (ll i = 0; i < M; ++i) {
    cin >> X[i];
  }
  while (Q--) {
    ll L, R;
    cin >> L >> R;
    --L, --R;
    vector<ll> xs;
    for (ll i = 0; i < M; ++i) {
      if (L <= i && i <= R) continue;
      xs.push_back(X[i]);
    }
    sort(xs.begin(), xs.end());
    vector<bool> used(xs.size());
    ll res = 0;
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < xs.size(); ++j) {
        if (xs[j] >= WV[i].first && !used[j]) {
          used[j] = true;
          res += WV[i].second;
          break;
        }
      }
    }
    printf("%lld\n", res);
  }
}