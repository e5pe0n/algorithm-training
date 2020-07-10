#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string W[10];

int main() {
  int N;
  cin >> N;
  cin >> W[0];
  bool flg = true;
  for (int i = 1; i < N; ++i) {
    cin >> W[i];
    if (W[i - 1][W[i - 1].size() - 1] != W[i][0]) {
      flg = false;
    } else {
      for (int j = 0; j < i; ++j) {
        if (W[j] == W[i]) {
          flg = false;
          break;
        }
      }
    }
  }
  if (flg) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}