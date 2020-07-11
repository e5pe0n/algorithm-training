#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_3N 300'000

typedef long long ll;

using namespace std;

int A[MAX_3N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 3 * N; ++i) {
    cin >> A[i];
  }
  sort(A, A + 3 * N);
  ll res = 0;
  for (int i = 3 * N - 2; i >= 3 * N - 2 - 2 * (N - 1); i -= 2) {
    res += A[i];
  }
  printf("%lld\n", res);
}