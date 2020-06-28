#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 100

using namespace std;

char A[MAX_H][MAX_H]{};

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < W; ++j) {
      A[i][j] = s[j];
    }
  }
  int i = 0;
  while (i < H) {
    int j = 0;
    while (j < W && A[i][j] == '.') {
      ++j;
    }
    if (j >= W) {
      for (int k = i; k < H - 1; ++k) {
        for (j = 0; j < W; ++j) {
          A[k][j] = A[k + 1][j];
        }
      }
      --H;
    } else {
      ++i;
    }
  }
  int j = 0;
  while (j < W) {
    int i = 0;
    while (i < H && A[i][j] == '.') {
      ++i;
    }
    if (i >= H) {
      for (int k = j; k < W - 1; ++k) {
        for (i = 0; i < H; ++i) {
          A[i][k] = A[i][k + 1];
        }
      }
      --W;
    } else {
      ++j;
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%c", A[i][j]);
    }
    printf("\n");
  }
}