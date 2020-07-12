#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (i == A[A[i] - 1] - 1) {
      ++cnt;
    }
  }
  printf("%d\n", (int)(cnt / 2));
}