#include <iostream>
#include <stdio.h>
#include <string>

#define M 26

using namespace std;

int H, W;
int C[M]{};

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < W; ++j) {
      ++C[s[j] - 'a'];
    }
  }
  int cnt_odd = 0;
  int cnt_4 = 0;
  for (int i = 0; i < M; ++i) {
    if (C[i] % 2 != 0) {
      ++cnt_odd;
    }
    cnt_4 += C[i] / 4;
  }
  if (H * W % 2 != 0) {
    if (cnt_odd == 1 && cnt_4 >= (H / 2) * (W / 2)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    if (cnt_odd == 0 && cnt_4 >= (H / 2) * (W / 2)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}