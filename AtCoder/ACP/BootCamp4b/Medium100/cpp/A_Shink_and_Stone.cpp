#include <iostream>
#include <stdio.h>

#define MAX_H 8

using namespace std;

string A[MAX_H];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < H - 1; ++i) {
    for (int j = 0; j < W - 1; ++j) {
      if (A[i + 1][j] == '#' && A[i][j + 1] == '#') {
        printf("Impossible\n");
        return 0;
      }
    }
  }
  printf("Possible\n");
}