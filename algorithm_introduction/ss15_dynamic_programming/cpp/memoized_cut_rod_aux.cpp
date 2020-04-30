#include <algorithm>
#include <chrono>
#include <stdio.h>

using namespace std;

int memoized_cut_rod_aux(int *p, int n, int *r) {
  if (n == 0)
    return 0;
  if (r[n] > 0)
    return r[n];
  for (int i = 0; i < n; ++i) {
    r[n] = max(r[n], p[i] + memoized_cut_rod_aux(p, n - 1 - i, r));
  }
  return r[n];
}

int main() {
  int N = 40;
  int p[40]{};
  int q[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  for (int i = 0; i < sizeof(q) / sizeof(q[0]); ++i) {
    p[i] = q[i];
  }
  int r[40]{};

  chrono::steady_clock::time_point start;
  chrono::steady_clock::time_point end;
  int res = 0;
  int64_t duration = 0;
  for (int i = 4; i <= 32; i += i) {
    memset(r, 0, 40);
    start = chrono::high_resolution_clock::now();
    res = memoized_cut_rod_aux(p, i, r);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    printf("n: %d, res: %d, duration: %lld[ns]\n", i, res, duration);
  }
}

// n: 4, res: 10, duration: 427[ns]
// n: 8, res: 22, duration: 921[ns]
// n: 16, res: 47, duration: 2119[ns]
// n: 32, res: 95, duration: 5450[ns]