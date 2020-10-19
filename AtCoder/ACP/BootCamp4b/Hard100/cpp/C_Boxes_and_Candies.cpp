#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

ll N, x;
ll A[MAX_N]{};
ll D[MAX_N]{};

int main() {
  cin >> N >> x;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N - 1; ++i) {
    D[i] = A[i + 1] + A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N - 2; ++i) {
    if (D[i] > x) {
      ll d = D[i] - x;
      ans += d;
      D[i] -= d;
      D[i + 1] -= min(d, A[i + 1]);
    }
  }
  if (D[N - 2] > x) {
    ll d = D[N - 2] - x;
    ans += d;
    D[N - 2] -= d;
  }
  printf("%lld\n", ans);
}