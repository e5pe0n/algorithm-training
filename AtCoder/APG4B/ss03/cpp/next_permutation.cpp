#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
  int N = 3;
  int a[] = {2, 1, 3};
  sort(a, a + N);
  do {
    for (int i = 0; i < N; ++i) {
      printf("%d ", a[i]);
    }
    printf("\n");
  } while (next_permutation(a, a + N));
}