#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

ll N;
ll A[MAX_N]{};

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    ans += A[i] / 2;
    if (A[i + 1] > 0) {
      A[i + 1] += A[i] % 2;
    }
  }
  ans += A[N - 1] / 2;
  printf("%lld\n", ans);
}