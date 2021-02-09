#include <bits/stdc++.h>
#define MAX_H 100
#define MAX_W 100
using namespace std;
typedef long long ll;

ll H, W;
string S[MAX_H];
string T[MAX_H];
string U[MAX_H];

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> S[i];
    T[i] = string(W, '.');
    U[i] = string(W, '.');
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if (S[i][j] == '.') continue;
      ll white = 0;
      for (ll di = -1; di < 2; ++di) {
        for (ll dj = -1; dj < 2; ++dj) {
          if (di == 0 && dj == 0) continue;
          ll _i = i + di;
          ll _j = j + dj;
          if (0 <= _i && _i < H && 0 <= j && _j < W && S[_i][_j] == '.')
            ++white;
        }
      }
      if (white == 0) { T[i][j] = U[i][j] = '#'; }
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      ll white = 0;
      ll black = 0;
      for (ll di = -1; di < 2; ++di) {
        for (ll dj = -1; dj < 2; ++dj) {
          ll _i = i + di;
          ll _j = j + dj;
          if (0 <= _i && _i < H && 0 <= _j && _j < W) {
            if (T[_i][_j] == '#')
              ++black;
            else
              ++white;
          }
        }
      }
      if (S[i][j] == '#' && black == 0) {
        puts("impossible");
        return 0;
      }
      if (S[i][j] == '.' && black > 0) {
        puts("impossible");
        return 0;
      }
    }
  }
  puts("possible");
  for (ll i = 0; i < H; ++i) {
    printf("%s\n", T[i].c_str());
  }
}