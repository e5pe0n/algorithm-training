#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  if (D == 0) {
    if (N == 100) {
      printf("101\n");
    } else if (N < 100) {
      printf("%d\n", N);
    }
  } else if (D == 1) {
    if (N == 100) {
      printf("%d\n", 100 * 101);
    } else {
      printf("%d\n", 100 * N);
    }
  } else {
    if (N == 100) {
      printf("%d\n", 10000 * 101);
    } else {
      printf("%d\n", 10000 * N);
    }
  }
}