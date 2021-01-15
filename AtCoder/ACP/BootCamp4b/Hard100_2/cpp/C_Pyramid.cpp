#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_X 100
#define MAX_Y 100
using namespace std;
typedef long long ll;

ll N;
ll X[MAX_N], Y[MAX_N], H[MAX_N];

void solve() {
  ll max_h = *max_element(H, H + N);
  for (ll cx = 0; cx <= MAX_X; ++cx) {
    for (ll cy = 0; cy <= MAX_Y; ++cy) {
      for (ll h = max_h; h <= max_h + 200; ++h) {
        bool f = true;
        for (ll i = 0; i < N; ++i) {
          if (H[i] != max(h - abs(X[i] - cx) - abs(Y[i] - cy), 0LL)) {
            f = false;
            break;
          }
        }
        if (f) {
          printf("%lld %lld %lld\n", cx, cy, h);
          return;
        }
      }
    }
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> H[i];
  }
  solve();
}