#include <iostream>
#include <stdio.h>

#define MAX_N 10000
#define MAX_H 100
#define MAX_W 100

using namespace std;

int A[MAX_N]{};
int B[MAX_W]{};

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int idx = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[idx] <= 0) {
        ++idx;
      }
      --A[idx];
      if (i % 2 == 0) {
        B[j] = idx + 1;
      } else {
        B[W - j - 1] = idx + 1;
      }
    }
    for (int j = 0; j < W; ++j) {
      printf("%d ", B[j]);
    }
    printf("\n");
  }
}