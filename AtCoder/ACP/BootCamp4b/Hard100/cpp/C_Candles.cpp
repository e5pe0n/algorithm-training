#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int X[MAX_N]{};

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  ll ans = 0;
  ll left = X[0];
  ll right = X[K - 1];
  if (left * right >= 0) {
    ans = max(abs(left), right);
  } else {
    ans = right - left + min(abs(left), right);
  }
  for (int i = 0; i < N - K + 1; ++i) {
    left = X[i];
    right = X[i + K - 1];
    if (left * right >= 0) {
      ans = min(ans, max(abs(left), right));
    } else {
      ans = min(ans, right - left + min(abs(left), right));
    }
  }
  printf("%lld\n", ans);
}