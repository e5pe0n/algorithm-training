#include <iostream>
#include <stdio.h>

#define MAX_H 1500
#define MAX_W 1500

using namespace std;
typedef long long ll;

int H, W, N, M;
int field[MAX_H][MAX_W];

int main() {
  cin >> H >> W >> N >> M;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    field[a - 1][b - 1] = 1;
  }
  for (int i = 0; i < M; ++i) {
    int c, d;
    cin >> c >> d;
    field[c - 1][d - 1] = -1;
  }

  ll res = 0;
  for (int i = 0; i < H; ++i) {
    int j = 0;
    while (j < W) {
      while (j < W && field[i][j] != 1) {
        ++j;
      }
      while (j < W && field[i][j] == 1) {
        ++j;
      }
      while (j < W && (field[i][j] == 0 || field[i][j] == 2)) {
        if (field[i][j] == 0) {
          ++res;
          field[i][j] = 2;
        }
        ++j;
      }
    }
    --j;
    while (j >= 0) {
      while (j >= 0 && field[i][j] != 1) {
        --j;
      }
      while (j >= 0 && field[i][j] == 1) {
        --j;
      }
      while (j >= 0 && (field[i][j] == 0 || field[i][j] == 2)) {
        if (field[i][j] == 0) {
          ++res;
          field[i][j] = 2;
        }
        --j;
      }
    }
  }
  for (int j = 0; j < W; ++j) {
    int i = 0;
    while (i < H) {
      while (i < H && field[i][j] != 1) {
        ++i;
      }
      while (i < H && field[i][j] == 1) {
        ++i;
      }
      while (i < H && (field[i][j] == 0 || field[i][j] == 2)) {
        if (field[i][j] == 0) {
          ++res;
          field[i][j] = 2;
        }
        ++i;
      }
    }
    --i;
    while (i >= 0) {
      while (i >= 0 && field[i][j] != 1) {
        --i;
      }
      while (i >= 0 && field[i][j] == 1) {
        --i;
      }
      while (i >= 0 && (field[i][j] == 0 || field[i][j] == 2)) {
        if (field[i][j] == 0) {
          ++res;
          field[i][j] = 2;
        }
        --i;
      }
    }
  }
  printf("%lld\n", res + N);
}