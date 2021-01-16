#include <bits/stdc++.h>
#define MAX_H 100
using namespace std;
typedef long long ll;

ll H, W;
string A[MAX_H];

void solve() {
  map<char, ll> C;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      ++C[A[i][j]];
    }
  }
  if (H > W) swap(H, W);
  if (H == 1) {
    ll odd = 0;
    for (auto p : C) {
      if (p.second % 2 != 0) ++odd;
    }
    if (H * W % 2 == 0 && odd == 0)
      puts("Yes");
    else if (H * W % 2 != 0 && odd == 1)
      puts("Yes");
    else
      puts("No");
    return;
  }
  ll four = 0;
  ll odd = 0;
  for (auto p : C) {
    if (p.second % 2 != 0) ++odd;
    if (p.second >= 4) { four += p.second / 4; }
  }
  if (H * W % 2 == 0 && odd == 0 && four >= (H / 2) * (W / 2))
    puts("Yes");
  else if (H * W % 2 != 0 && odd == 1 && four >= (H / 2) * (W / 2))
    puts("Yes");
  else
    puts("No");
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> A[i];
  }
  solve();
}