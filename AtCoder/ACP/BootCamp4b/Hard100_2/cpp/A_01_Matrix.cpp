#include <bits/stdc++.h>
#define MAX_H 1000
#define MAX_W 1000
using namespace std;
typedef long long ll;

ll H, W, A, B;
ll res[MAX_H][MAX_W];

void solve() {
  if ((A * 2 > W) || (B * 2 > H)) {
    puts("No");
  } else {
    for (ll i = 0; i < H; ++i) {
      for (ll j = 0; j < W; ++j) {
        if (j < A && i < B) {
          res[i][j] = 1;
        } else if (j < A && i >= B) {
          res[i][j] = 0;
        } else if (j >= A && i < B) {
          res[i][j] = 0;
        } else if (j >= A && i >= B) {
          res[i][j] = 1;
        }
      }
    }
    for (ll i = 0; i < H; ++i) {
      for (ll j = 0; j < W; ++j) {
        printf("%lld", res[i][j]);
      }
      puts("");
    }
  }
}

int main() {
  cin >> H >> W >> A >> B;
  solve();
}