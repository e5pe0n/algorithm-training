#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'000
#define MAX_N 200'000
#define MAX_M 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll A[MAX_N];
ll B[MAX_N];
ll X[MAX_M], Y[MAX_M];

void solve() {
  for (ll i = 0; i < N; ++i) {
    B[i] = A[i];
  }
  vector<pll> V;
  for (ll i = 0; i < M; ++i) {
    V.push_back({X[i], Y[i]});
  }
  sort(V.begin(), V.end());
  ll res = -INF;
  for (auto [x, y] : V) {
    res = max(res, A[y] - B[x]);
    B[y] = min(B[x], B[y]);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }
  solve();
}