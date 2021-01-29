#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 20
#define MAX_W 20
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll di[] = {1, 0, -1, 0};
const ll dj[] = {0, 1, 0, -1};

ll H, W;
string S[MAX_H];
ll d[MAX_H][MAX_W];

ll bfs(pll s) {
  for (ll i = 0; i < H; ++i) {
    fill(d[i], d[i] + W, INF);
  }
  d[s.first][s.second] = 0;
  queue<pll> q;
  q.push(s);
  ll res = 0;
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    for (ll k = 0; k < 4; ++k) {
      ll _i = i + di[k];
      ll _j = j + dj[k];
      if (0 <= _i && _i < H && 0 <= _j && _j < W && S[_i][_j] == '.'
          && d[_i][_j] > d[i][j] + 1) {
        d[_i][_j] = d[i][j] + 1;
        q.push({_i, _j});
        res = max(res, d[_i][_j]);
      }
    }
  }
  return res;
}

void solve() {
  ll res = 0;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if (S[i][j] == '.') { res = max(res, bfs({i, j})); }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}