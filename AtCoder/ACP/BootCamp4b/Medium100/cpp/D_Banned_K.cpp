#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

typedef long long ll;

using namespace std;

int A[MAX_N]{};
int C[MAX_N]{};

ll comb(int n) {
  if (n <= 1) {
    return 0;
  } else {
    return (ll)n * (n - 1) / 2;
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    A[i] = a - 1;
    ++C[a - 1];
  }

  ll t = 0;
  for (int i = 0; i < N; ++i) {
    t += comb(C[i]);
  }

  for (int i = 0; i < N; ++i) {
    printf("%lld\n", t - comb(C[A[i]]) + comb(C[A[i]] - 1));
  }
}