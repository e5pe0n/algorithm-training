#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 500

using namespace std;

int C[MAX_N]{};
int S[MAX_N]{};
int F[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    cin >> C[i] >> S[i] >> F[i];
  }
  if (N == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < N - 1; ++i) {
    int t = S[i] + C[i];
    for (int j = i + 1; j < N - 1; ++j) {
      t = max(S[j], (int)ceil((double)t / F[j]) * F[j]) + C[j];
    }
    printf("%d\n", t);
  }
  printf("0\n");
}