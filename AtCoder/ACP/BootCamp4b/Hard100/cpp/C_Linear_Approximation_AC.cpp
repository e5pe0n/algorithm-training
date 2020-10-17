#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_A 1'000'000'000

typedef long long ll;

using namespace std;

int N;
ll A[MAX_N]{};

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    A[i - 1] = a - i;
  }
  sort(A, A + N);
  ll sum_a = 0;
  ll _min_a = A[0];
  for (int i = 0; i < N; ++i) {
    A[i] -= _min_a;
    sum_a += A[i];
  }
  ll min_a = A[0];
  ll max_a = A[N - 1];
  int idx = 0;
  ll n = N;
  ll _n = 0;
  ll _sum_a = 0;
  ll ans = sum_a;
  for (ll b = min_a; b <= max_a; ++b) {
    ll remain_plus = sum_a - n * b;
    ll remain_minus = _n * b - _sum_a;
    ans = min(ans, remain_plus + remain_minus);
    while (b == A[idx] && b != max_a) {
      --n;
      ++_n;
      sum_a -= A[idx];
      _sum_a += A[idx++];
    }
  }
  printf("%lld\n", ans);
}