#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_H 500
#define MAX_W 500

using namespace std;

int H, W;
int A[MAX_H][MAX_W]{};
bool used[MAX_H][MAX_W]{};

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> V;
  int c = 0;
  for (int i = 0; i < H; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; ++j) {
        ++c;
        if (A[i][j] % 2 == 0 || c == H * W) {
          continue;
        }
        if (j < W - 1) {
          ++A[i][j + 1];
          V.push_back(vector<int>{i, j, i, j + 1});
        } else {
          ++A[i + 1][j];
          V.push_back(vector<int>{i, j, i + 1, j});
        }
      }
    } else {
      for (int j = W - 1; j >= 0; --j) {
        ++c;
        if (A[i][j] % 2 == 0 || c == H * W) {
          continue;
        }
        if (j > 0) {
          ++A[i][j - 1];
          V.push_back(vector<int>{i, j, i, j - 1});
        } else {
          ++A[i + 1][j];
          V.push_back(vector<int>{i, j, i + 1, j});
        }
      }
    }
  }
  printf("%d\n", (int)V.size());
  for (auto v : V) {
    for (int i = 0; i < v.size(); ++i) {
      printf("%d", v[i] + 1);
      if (i < v.size() - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}