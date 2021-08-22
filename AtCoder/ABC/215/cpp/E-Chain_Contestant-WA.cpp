// WA
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pss = pair<string, string>;

const ll MAX_N = 1000;
const ll MOD = 998244353;
ll N;
string S;
vector<ll> pos[10];
ll sum[10][MAX_N];
map<ll, ll> memo[MAX_N][MAX_N][10];

ll f(ll start, ll end, ll n, char c) {
  map<ll, ll> &m = memo[start][end][c - 'A'];
  if (m[n] > 0) return m[n];
  if (start >= end || n == 0 || c > 'J') return 1;
  ll all_removed =
      f(start, end, n - (sum[c - 'A'][end] - sum[c - 'A'][start]), c + 1);
  ll res = 0;
  for (ll i = 0; i < pos[c - 'A'].size(); ++i) {
    for (ll j = i; j < pos[c - 'A'].size(); ++j) {
      ll left = pos[c - 'A'][i];
      ll right = pos[c - 'A'][j];
      if (start <= left && right <= end) {
        ll n_left = (left - start) - (sum[c - 'A'][left] - sum[c - 'A'][start]);
        ll res_left = f(start, left, n_left, c + 1);
        ll n_right =
            (end - (right + 1)) - (sum[c - 'A'][end] - sum[c - 'A'][right + 1]);
        ll res_right = f(right + 1, end, n_right, c + 1);
        res = (res + res_left * res_right % MOD) % MOD;
      }
    }
  }
  m[n] = (all_removed + res) % MOD;
  return m[n];
}

int main() {
  cin >> N >> S;
  for (char c = 'A'; c <= 'J'; ++c) {
    for (ll i = 0; i < N; ++i) {
      sum[c - 'A'][i + 1] = sum[c - 'A'][i];
      if (S[i] == c) {
        ++sum[c - 'A'][i + 1];
        pos[c - 'A'].push_back(i);
      }
    }
  }
  printf("%lld\n", ((f(0, N, N, 'A') - 1) % MOD + MOD) % MOD);
}