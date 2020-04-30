#include <algorithm>
#include <chrono>
#include <stdio.h>

using namespace std;

int bottom_up_cut_rod(int *p, int n) {
  int r[40]{};
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= j; ++i) {
      r[j] = max(r[j], p[i - 1] + r[j - i]);
    }
  }
  return r[n];
}

int main() {
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
    start = chrono::high_resolution_clock::now();
    res = bottom_up_cut_rod(p, i);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    printf("n: %d, res: %d, duration: %lld[ns]\n", i, res, duration);
  }
}

// n: 4, res: 10, duration: 444[ns]
// n: 8, res: 22, duration: 815[ns]
// n: 16, res: 47, duration: 1839[ns]
// n: 32, res: 95, duration: 5934[ns]