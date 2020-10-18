#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_H 1000
#define MAX_W 1000

using namespace std;

int H, W, A, B;

int main() {
  cin >> H >> W >> A >> B;
  if (A == 0 && B == 0) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        printf("1");
      }
      printf("\n");
    }
  } else if (A == 0) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (i < B) {
          printf("1");
        } else {
          printf("0");
        }
      }
      printf("\n");
    }
  } else if (B == 0) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (j < A) {
          printf("1");
        } else {
          printf("0");
        }
      }
      printf("\n");
    }
  } else {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if ((i < B && j < A) || (i >= B && j >= A)) {
          printf("1");
        } else {
          printf("0");
        }
      }
      printf("\n");
    }
  }
}