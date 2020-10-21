#include <iostream>
#include <stdio.h>

#define MAX_B 60
#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

ll N;
ll C[MAX_B]{};

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    int j = 0;
    while (a > 0) {
      if (a & 1) {
        ++C[j];
      }
      ++j;
      a >>= 1;
    }
  }
  ll ans = 0;
  ll x = 1;
  for (int i = 0; i < MAX_B; ++i) {
    ans = (ans + (C[i] * (N - C[i]) % MOD) * x % MOD) % MOD;
    x = x * 2 % MOD;
  }
  printf("%lld\n", ans);
}