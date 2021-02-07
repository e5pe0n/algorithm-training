#include <bits/stdc++.h>
#define MAX_H 10
#define MAX_W 10
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll H, W;
string S[MAX_H];
pll dxdy[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> S[i];
  }
  ll res = 0;
  for (ll i = 0; i < H - 1; ++i) {
    for (ll j = 0; j < W - 1; ++j) {
      ll cnt = 0;
      for (ll k = 0; k < 4; ++k) {
        ll dx = dxdy[k].first;
        ll dy = dxdy[k].second;
        ll x = i + dx;
        ll y = j + dy;
        if (S[x][y] == '#') ++cnt;
      }
      if (cnt == 1 || cnt == 3) ++res;
    }
  }
  printf("%lld\n", res);
}