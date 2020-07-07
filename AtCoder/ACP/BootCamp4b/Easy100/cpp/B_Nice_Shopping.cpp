#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_A 100'000

using namespace std;

int A[MAX_A];
int B[MAX_A];

int main() {
  int NA, NB, M;
  cin >> NA >> NB >> M;
  int a = MAX_A + 1;
  for (int i = 0; i < NA; ++i) {
    cin >> A[i];
    a = min(a, A[i]);
  }
  int b = MAX_A + 1;
  for (int i = 0; i < NB; ++i) {
    cin >> B[i];
    b = min(b, B[i]);
  }

  int res = a + b;
  for (int i = 0; i < M; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    res = min(A[x - 1] + B[y - 1] - c, res);
  }
  printf("%d\n", res);
}