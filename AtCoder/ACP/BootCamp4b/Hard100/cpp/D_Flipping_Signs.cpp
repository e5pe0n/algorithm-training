#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  int cnt = 0;
  int min_n = MAX_N;
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    ans += abs(A[i]);
    if (A[i] <= 0) {
      ++cnt;
    }
    min_n = min(min_n, abs(A[i]));
  }
  if (cnt % 2 == 0) {
    printf("%lld\n", ans);
  } else {
    printf("%lld\n", ans - 2 * min_n);
  }
}