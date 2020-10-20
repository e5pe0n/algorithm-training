#include <iostream>
#include <stdio.h>

#define MAX_N 100'000
#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

ll N;
ll C[MAX_N]{};

int main() {
  cin >> N;
  int cc = 3;
  ll ans = 1;
  for (int i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    if (a == 0) {
      ans = ((ans % MOD) * (cc--)) % MOD;
    } else {
      ans = ans * C[a - 1] % MOD;
      --C[a - 1];
    }
    ++C[a];
  }
  printf("%lld\n", ans);
}