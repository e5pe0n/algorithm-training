#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    A[a - 1] = i;
  }
  for (int i = 0; i < N; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");
}