#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll N;
map<ll, vector<ll>> M;
ll dp[MAX_N + 2][2];
vector<ll> V;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll X, C;
    cin >> X >> C;
    M[C].push_back(X);
  }
  V.push_back(0);
  for (auto p : M) {
    vector<ll> v = p.second;
    sort(v.begin(), v.end());
    M[p.first] = v;
    V.push_back(p.first);
  }
  V.push_back(0);
  M[0] = vector<ll>{0};
  for (ll i = 0; i < MAX_N + 2; ++i) {
    dp[i][0] = dp[i][1] = INF;
  }
  dp[0][0] = dp[0][1] = 0;
  for (ll i = 0; i < V.size() - 1; ++i) {
    vector<ll> prv_v = M[V[i]];
    ll prv_left = prv_v[0];
    ll prv_right = prv_v[prv_v.size() - 1];
    vector<ll> nxt_v = M[V[i + 1]];
    ll nxt_left = nxt_v[0];
    ll nxt_right = nxt_v[nxt_v.size() - 1];

    // prv_left -> nxt_right -> nxt_left
    if (prv_left <= nxt_right)
      dp[i + 1][0] =
          min(dp[i + 1][0],
              dp[i][0] + (nxt_right - prv_left) + (nxt_right - nxt_left));
    else
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (prv_left - nxt_left));
    // prv_right -> nxt_right -> nxt_left
    if (prv_right <= nxt_right)
      dp[i + 1][0] =
          min(dp[i + 1][0],
              dp[i][1] + (nxt_right - prv_right) + (nxt_right - nxt_left));
    else
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (prv_right - nxt_left));

    // prv_left -> nxt_left -> nxt_right
    if (nxt_left <= prv_left)
      dp[i + 1][1] =
          min(dp[i + 1][1],
              dp[i][0] + (prv_left - nxt_left) + (nxt_right - nxt_left));
    else
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (nxt_right - prv_left));
    // prv_right -> nxt_left -> nxt_right
    if (nxt_left <= prv_right)
      dp[i + 1][1] =
          min(dp[i + 1][1],
              dp[i][1] + (prv_right - nxt_left) + (nxt_right - nxt_left));
    else
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (nxt_right - prv_right));
  }
  printf("%lld\n", dp[V.size() - 1][0]);
}