#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000
#define MAX_A 1'000'000'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  int a = MAX_A;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    a = min(a, A[i]);
  }
  int b = a;
  while (true) {
    for (int i = 0; i < N; ++i) {
      int _b = A[i] % a;
      if (_b > 0 && _b < a) {
        b = _b;
      }
    }
    if (a == b) {
      printf("%d\n", b);
      return 0;
    }
    a = b;
  }
}