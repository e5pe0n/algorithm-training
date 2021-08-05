#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_H = 2000;
const ll MAX_W = 2000;
const ll di[] = {0, 1, 0, -1};
const ll dj[] = {1, 0, -1, 0};
ll H, W, Q;
bool board[MAX_H][MAX_W];

ll par[MAX_H * MAX_W], rnk[MAX_H * MAX_W];

void init() {
  for (ll i = 0; i < H * W; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll u) {
  if (par[u] == u) return u;
  return par[u] = find(par[u]);
}

void unite(ll u, ll v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (rnk[u] < rnk[v])
    par[u] = v;
  else {
    par[v] = u;
    if (rnk[u] == rnk[v]) ++rnk[u];
  }
}

bool same(ll u, ll v) {
  return find(u) == find(v);
}

ll vertex(ll i, ll j) {
  return i * W + j;
}

int main() {
  cin >> H >> W >> Q;
  init();
  while (Q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll r, c;
      cin >> r >> c;
      --r, --c;
      board[r][c] = true;
      for (ll k = 0; k < 4; ++k) {
        ll _r = r + di[k];
        ll _c = c + dj[k];
        if (0 <= _r && _r < H && 0 <= _c && _c < W && board[_r][_c])
          unite(vertex(r, c), vertex(_r, _c));
      }
    } else {
      ll ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      --ra, --ca, --rb, --cb;
      if (board[ra][ca] && board[rb][cb]
          && same(vertex(ra, ca), vertex(rb, cb)))
        puts("Yes");
      else
        puts("No");
    }
  }
}