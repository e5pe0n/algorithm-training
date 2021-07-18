// WA
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ppll = pair<pll, pll>;

const ll MAX_H = 1000;
const ll MAX_W = 1000;
const ll INF = 1e18;
ll H, W;
ll C;
ll A[MAX_H][MAX_W];
ll D[MAX_H][MAX_W];

const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {1, 0, -1, 0};

void bfs(vector<pll> &mins, ll mi) {
  queue<ppll> q;
  for (auto p : mins) {
    q.push({p, p});
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      D[i][j] = INF;
    }
  }
  while (q.size()) {
    auto [prv, src] = q.front();
    ll i = prv.first;
    ll j = prv.second;
    q.pop();
    for (ll k = 0; k < 4; ++k) {
      ll _i = i + dx[k];
      ll _j = j + dy[k];
      if (0 <= _i && _i < H && 0 <= _j && _j < W
          && !(_i == src.first && _j == src.second)) {
        ll t =
            mi + A[_i][_j] + C * (abs(src.first - _i) + abs(src.second - _j));
        if (D[_i][_j] > t) {
          D[_i][_j] = t;
          q.push({{_i, _j}, src});
        }
      }
    }
  }
}

int main() {
  cin >> H >> W >> C;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  ll mi = A[0][0];
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      mi = min(mi, A[i][j]);
    }
  }
  vector<pll> mins;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if (A[i][j] == mi) mins.push_back({i, j});
    }
  }
  if (mins.size() == H * W) {
    printf("%lld\n", mi + mi + C);
    return 0;
  }
  bfs(mins, mi);
  ll res = INF;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      res = min(res, D[i][j]);
    }
  }
  printf("%lld\n", res);
}