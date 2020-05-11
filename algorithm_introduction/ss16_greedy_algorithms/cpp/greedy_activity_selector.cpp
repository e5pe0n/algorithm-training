#include <stdio.h>

using namespace std;

// (s, f) pairs are sorted f
int s[]{1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
int f[]{4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
int A[20];

void greedy_recursive_selector(int *s, int s_length, int *f) {
  A[0] = 0;
  int i = 1;
  int k = 0;
  for (int m = 1; m < s_length; ++m) {
    if (s[m] >= f[k]) {
      A[i++] = m;
      k = m;
    }
  }
}

int main() {
  for (int i = 0; i < 20; ++i) {
    A[i] = -1;
  }

  greedy_recursive_selector(s, sizeof(s) / sizeof(s[0]), f);

  int i = 0;
  while (A[i] >= 0) {
    printf("%d, ", A[i++]); // 0, 3, 7, 10,
  }
  printf("\n");
}