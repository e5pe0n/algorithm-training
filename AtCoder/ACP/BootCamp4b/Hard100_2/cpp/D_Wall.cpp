#include <bits/stdc++.h>
#define MAX_H 200
#define MAX_W 200
#define INF 1'000'000'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll H, W;
ll C[10][10];
ll A[MAX_H][MAX_W];

void warshall_floyd() {
  for (int k = 0; k < 10; ++k) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }
}

void solve() {
  warshall_floyd();
  ll res = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] != -1) { res += C[A[i][j]][1]; }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> C[i][j];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  solve();
}