#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 2000
#define MAX_W 2000
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;

int H, W;
string S[MAX_H];
ll d[MAX_W], col[MAX_W], dia[MAX_H + MAX_W - 1];

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  for (int i = 0; i < H; ++i) {
    ll t = 0;
    for (int j = 0; j < W; ++j) {
      int k = H - 1 - i + j;
      if (i == 0 && j == 0) {
        d[0] = 1;
        t = 1;
        col[j] = 1;
        dia[k] = 1;
      } else if (S[i][j] == '#' || (t == 0 && col[j] == 0 && dia[k] == 0)) {
        d[j] = 0;
        t = 0;
        col[j] = 0;
        dia[k] = 0;
      } else {
        d[j] = (t + col[j] + dia[k]) % MOD;
        t = (t + d[j]) % MOD;
        col[j] = (col[j] + d[j]) % MOD;
        dia[k] = (dia[k] + d[j]) % MOD;
      }
    }
    // printf("d  =");
    // for (int j = 0; j < W; ++j) {
    //   printf("%lld%c", d[j], j == W - 1 ? '\n' : ' ');
    // }
    // printf("col=");
    // for (int j = 0; j < W; ++j) {
    //   printf("%lld%c", col[j], j == W - 1 ? '\n' : ' ');
    // }
    // printf("\n");
  }
  printf("%lld\n", d[W - 1]);
}