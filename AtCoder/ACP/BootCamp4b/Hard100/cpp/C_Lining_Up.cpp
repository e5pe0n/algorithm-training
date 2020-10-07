#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000
#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

int A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  ll t = 1;
  int i = 0;
  if (N % 2 != 0) {
    if (A[0] != 0) {
      t = 0;
    } else {
      ++i;
    }
  }
  for (i; i < N; i += 2) {
    if (A[i] == i + 1 && A[i + 1] == i + 1) {
      t = (t * 2) % MOD;
    } else {
      t = 0;
      break;
    }
  }
  printf("%lld\n", t);
}