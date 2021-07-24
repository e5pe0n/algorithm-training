#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 8;
const ll di[] = {0, 1, 0, -1};
const ll dj[] = {1, 0, -1, 0};
ll N, K;
string S[MAX_N];
set<ll> used;
ll res = 0;

bool get_bit(ll n, ll i) {
  return (n & (1LL << i)) != 0;
}

ll set_bit(ll n, ll i) {
  return n | (1LL << i);
}

ll toggle_bit(ll n, ll i) {
  return n ^ (1LL << i);
}

ll idx(ll i, ll j) {
  return i * N + j;
}

void dfs(ll r, ll board) {
  if (used.find(board) != used.end()) return;
  used.insert(board);
  if (r == K) {
    ++res;
    return;
  }
  vector<pll> nxts;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (S[i][j] != '#') {
        bool f = false;
        for (ll k = 0; k < 4; ++k) {
          ll _i = i + di[k];
          ll _j = j + dj[k];
          if (0 <= _i && _i < N && 0 <= _j && _j < N) {
            if (get_bit(board, idx(_i, _j))) f = true;
          }
        }
        if (f) nxts.push_back({i, j});
      }
    }
  }
  for (auto [i, j] : nxts)
    dfs(r + 1, set_bit(board, idx(i, j)));
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
  }
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (S[i][j] != '#') dfs(1, set_bit(0, idx(i, j)));
    }
  }
  printf("%lld\n", res);
}