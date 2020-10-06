#include <iostream>
#include <stdio.h>

#define MOD 1'000'000'007
#define MAX_N 1001

typedef long long ll;

using namespace std;

int C[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 2; i <= N; ++i) {
    int n = i;
    for (int j = 2; j * j <= n; ++j) {
      if (n % j != 0) {
        continue;
      }
      while (n % j == 0) {
        ++C[j];
        n /= j;
      }
    }
    if (n > 1) {
      ++C[n];
    }
  }
  ll ans = 1;
  for (int i = 2; i <= N; ++i) {
    if (C[i] > 0) {
      ans = (ans * (C[i] + 1)) % MOD;
    }
  }
  printf("%lld\n", ans);
}