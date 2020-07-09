#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  int x, y;
  cin >> x >> y;
  A[0] = x;
  A[1] = y;
  if (x < y) {
    swap(x, y);
  }
  for (int i = 2; i < N; ++i) {
    cin >> A[i];
    if (x <= A[i]) {
      y = x;
      x = A[i];
    } else if (y < A[i]) {
      y = A[i];
    }
  }
  if (x == y) {
    for (int i = 0; i < N; ++i) {
      printf("%d\n", x);
    }
  } else {
    for (int i = 0; i < N; ++i) {
      if (A[i] == x) {
        printf("%d\n", y);
      } else {
        printf("%d\n", x);
      }
    }
  }
}