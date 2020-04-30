#include <algorithm>
#include <chrono>
#include <limits>
#include <stdio.h>

using namespace std;

int I_MIN = numeric_limits<int>::min();

int cut_rod(int *p, int n) {
  if (n == 0)
    return 0;
  int q = I_MIN;
  for (int i = 0; i < n; ++i) {
    q = max(q, p[i] + cut_rod(p, n - i - 1));
  }
  return q;
}

int main() {
  int n = 32;
  int p[40]{};
  int q[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  for (int i = 0; i < 10; ++i) {
    p[i] = q[i];
  }

  auto start = chrono::high_resolution_clock::now();
  int res = cut_rod(p, n);
  auto end = chrono::high_resolution_clock::now();
  int64_t duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  printf("n: %d, res: %d, duration: %lld[ns]\n", n, res, duration);
}

// n: 4, res: 10, duration: 709[ns]
// n: 8, res: 22, duration: 4969[ns]
// n: 16, res: 47, duration: 957587[ns]
// n: 32, res: 95, duration: 55477300831[ns]