#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

using namespace std;

int A[MAX_N]{};
int B[MAX_N]{};

int main() {
  int N, H;
  cin >> N >> H;
  int max_a = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    max_a = max(max_a, A[i]);
  }
  sort(B, B + N, [](int left, int right) { return left > right; });
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (B[i] < max_a) {
      break;
    }
    H -= B[i];
    ++cnt;
    if (H <= 0) {
      printf("%d\n", cnt);
      return 0;
    }
  }
  cnt += (int)ceil((double)H / max_a);
  printf("%d\n", cnt);
}