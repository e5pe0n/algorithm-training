#include <bits/stdc++.h>
#define MAX_N 200'000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, D, A;
ll X[MAX_N + 1], H[MAX_N];
ll R[MAX_N], sum[MAX_N + 1];

void solve() {
  vector<pll> V;
  for (int i = 0; i < N; ++i) {
    V.push_back({X[i], H[i]});
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < N; ++i) {
    X[i] = V[i].first;
    H[i] = V[i].second;
  }
  X[N] = INF;
  for (int i = 0; i < N; ++i) {
    auto idx = upper_bound(X, X + N + 1, X[i] + 2 * D) - X;
    R[i] = idx - 1;
  }
  ll res = 0;
  for (int i = N - 1; i >= 0; --i) {
    ll d = max(0LL, H[i] - sum[i + 1] + sum[R[i] + 1]);
    ll c = (d + A - 1) / A;
    res += c;
    sum[i] = sum[i + 1] + c * A;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> D >> A;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> H[i];
  }
  solve();
}