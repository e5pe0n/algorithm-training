#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 50
#define MAX_W 50
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll di[] = {0, 1, 0, -1};
const ll dj[] = {1, 0, -1, 0};

ll H, W;
string S[MAX_H];
ll d[MAX_H][MAX_W];

void bfs() {
  for (ll i = 0; i < H; ++i) {
    fill(d[i], d[i] + W, INF);
  }
  d[0][0] = 1;
  queue<pll> q;
  q.push({0, 0});
  while (!q.empty()) {
    ll i, j;
    tie(i, j) = q.front();
    q.pop();
    for (ll k = 0; k < 4; ++k) {
      ll ni = i + di[k];
      ll nj = j + dj[k];
      if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] != '#' && d[ni][nj] > d[i][j] + 1) {
        d[ni][nj] = d[i][j] + 1;
        q.push({ni, nj});
      }
    }
  }
}

void solve() {
  ll b = 0;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if (S[i][j] == '#') ++b;
    }
  }
  bfs();
  ll res;
  if (d[H - 1][W - 1] == INF) {
    res = -1;
  } else {
    res = (H * W - d[H - 1][W - 1]) - b;
  }
  printf("%lld\n", res);
};

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}