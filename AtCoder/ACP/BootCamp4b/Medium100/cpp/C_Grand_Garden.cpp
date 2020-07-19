#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int H[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  int res = 0;
  while (true) {
    int i = 0;
    int cnt = 0;
    while (i < N) {
      while (i < N && H[i] <= 0) {
        ++i;
      }
      if (i >= N) {
        break;
      }
      while (i < N && H[i] > 0) {
        --H[i];
        ++i;
      }
      ++cnt;
    }
    if (cnt == 0) {
      printf("%d\n", res);
      return 0;
    } else {
      res += cnt;
    }
  }
}