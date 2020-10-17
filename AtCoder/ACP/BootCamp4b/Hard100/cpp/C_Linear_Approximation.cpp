#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000

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
  int mid = N / 2;
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += abs(A[i] - A[mid]);
  }
  if (N % 2 == 0) {
    int _mid = mid + 1;
    ll _ans = 0;
    for (int i = 0; i < N; ++i) {
      _ans += abs(A[i] - A[_mid]);
    }
    ans = min(ans, _ans);
  }
  printf("%lld\n", ans);
}