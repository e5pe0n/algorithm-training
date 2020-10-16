#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int N;
ll A[MAX_N]{};

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  ll ans = 0;
  if (N % 2 == 0) {
    int i = 0;
    for (; i < N / 2 - 1; ++i) {
      ans -= A[i] * 2;
    }
    ans -= A[i++];
    ans += A[i++];
    for (; i < N; ++i) {
      ans += A[i] * 2;
    }
  } else {
    ll ans1 = 0;
    int i = 0;
    for (; i < (N - 3) / 2; ++i) {
      ans1 -= A[i] * 2;
    }
    ans1 -= A[i++];
    ans1 -= A[i++];
    for (; i < N; ++i) {
      ans1 += A[i] * 2;
    }
    ll ans2 = 0;
    i = 0;
    for (; i < N / 2; ++i) {
      ans2 -= A[i] * 2;
    }
    ans2 += A[i++];
    ans2 += A[i++];
    for (; i < N; ++i) {
      ans2 += A[i] * 2;
    }
    ans = max(ans1, ans2);
  }
  printf("%lld\n", ans);
}