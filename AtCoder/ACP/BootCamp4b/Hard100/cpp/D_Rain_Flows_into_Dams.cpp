#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll t = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      t += A[i];
    } else {
      t -= A[i];
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld ", t);
    t = -t + A[i] * 2;
  }
  printf("\n");
}