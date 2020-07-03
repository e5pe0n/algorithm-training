#include <bitset>
#include <iostream>
#include <stdio.h>

#define MAX_N 4

using namespace std;

int T[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }

  int res = 1'000'000'000;
  for (int i = 0; i < (1 << N); ++i) {
    bitset<4> b(i);
    int t0 = 0;
    int t1 = 0;
    for (int j = 0; j < N; ++j) {
      if (b.test(j)) {
        t0 += T[j];
      } else {
        t1 += T[j];
      }
    }
    res = min(res, max(t0, t1));
  }
  printf("%d\n", res);
}