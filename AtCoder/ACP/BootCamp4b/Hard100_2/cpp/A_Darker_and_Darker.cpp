#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 1000
#define MAX_W 1000
using namespace std;
typedef long long ll;

const ll di[] = {0, 1, 0, -1};
const ll dj[] = {1, 0, -1, 0};

ll H, W;
string A[MAX_H];

ll bfs() {
  queue<vector<ll>> q;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if (A[i][j] == '#') { q.push({i, j, 0}); }
    }
  }
  ll res = 0;
  while (q.size()) {
    vector<ll> p = q.front();
    q.pop();
    ll i = p[0];
    ll j = p[1];
    ll c = p[2];
    for (ll k = 0; k < 4; ++k) {
      ll _i = i + di[k];
      ll _j = j + dj[k];
      if (0 <= _i && _i < H && 0 <= _j && _j < W && A[_i][_j] == '.') {
        q.push({_i, _j, c + 1});
        res = max(res, c + 1);
        A[_i][_j] = '#';
      }
    }
  }
  return res;
}

void solve() {
  printf("%lld\n", bfs());
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> A[i];
  }
  solve();
}