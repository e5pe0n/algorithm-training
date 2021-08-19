#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
const ll MAX_X = 1000;
const ll MAX_Y = 1000;
ll N;

struct Rect {
  ll lx, ly, rx, ry;
};

Rect rects[MAX_N];
ll lefts[MAX_Y + 1][MAX_X + 1];
ll rights[MAX_Y + 1][MAX_X + 1];
ll A[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> rects[i].lx >> rects[i].ly >> rects[i].rx >> rects[i].ry;
  }
  for (ll y = 0; y <= MAX_Y; ++y) {
    for (auto rect : rects) {
      if (rect.ly <= y && y < rect.ry) {
        ++lefts[y][rect.lx];
        ++rights[y][rect.rx];
      }
    }
  }
  for (ll y = 0; y <= MAX_Y; ++y) {
    ll k = 0;
    for (ll x = 0; x <= MAX_X; ++x) {
      k -= rights[y][x];
      k += lefts[y][x];
      ++A[k];
    }
  }
  for (ll k = 1; k <= N; ++k) {
    printf("%lld\n", A[k]);
  }
}