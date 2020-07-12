#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int B[MAX_N];

int main() {
  int N;
  cin >> N;
  int max_height = 0;
  int max_idx = 0;
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
    if (max_height < B[i]) {
      max_height = B[i];
      max_idx = i;
    }
  }

  int cnt = 0;
  int i = max_idx - 1;
  while (i > 0) {
    if (B[i - 1] > B[i]) {
      int x = B[i - 1];
      int k = i - 1;
      int j = i;
      while (x > B[j]) {
        B[j - 1] = B[j];
        ++j;
        ++cnt;
      }
      B[j - 1] = x;
      i = k;
    } else {
      --i;
    }
  }
  i = max_idx + 1;
  while (i < N - 1) {
    if (B[i + 1] > B[i]) {
      int x = B[i + 1];
      int k = i + 1;
      int j = i;
      while (x > B[j]) {
        B[j + 1] = B[j];
        --j;
        ++cnt;
      }
      B[j + 1] = x;
      i = k;
    } else {
      ++i;
    }
  }
  printf("%d\n", cnt);
}