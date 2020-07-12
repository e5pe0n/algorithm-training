#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int A[][2] = {{1, 3}, {7, 5}, {4, 6}};
  auto comp = [](const int *a1, const int *a2) { return a1[0] < a2[0]; };
  // sort(A, A + 3, comp);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}