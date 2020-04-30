#include <algorithm>
#include <stdio.h>

using namespace std;

void extend_bottom_up_cut_rod(int *p, int *r, int *s, int n) {
  memset(r, 0, 40);
  memset(s, 0, 40);
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= j; ++i) {
      if (r[j] < p[i - 1] + r[j - i]) {
        r[j] = p[i - 1] + r[j - i];
        s[j] = i;
      }
    }
  }
}

void print_cut_rod_solution(int *p, int n) {
  int r[40]{};
  int s[40]{};
  extend_bottom_up_cut_rod(p, r, s, n);
  printf("n: %d, sol: [", n);
  while (n > 0) {
    printf("%d, ", s[n]);
    n -= s[n];
  }
  printf("]\n");
}

int main() {
  int p[40]{};
  int q[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  for (int i = 0; i < sizeof(q) / sizeof(q[0]); ++i) {
    p[i] = q[i];
  }

  for (int i = 1; i <= 10; ++i) {
    print_cut_rod_solution(p, i);
  }
}

// n: 1, sol: [1, ]
// n: 2, sol: [2, ]
// n: 3, sol: [3, ]
// n: 4, sol: [2, 2, ]
// n: 5, sol: [2, 3, ]
// n: 6, sol: [6, ]
// n: 7, sol: [1, 6, ]
// n: 8, sol: [2, 6, ]
// n: 9, sol: [3, 6, ]
// n: 10, sol: [10, ]