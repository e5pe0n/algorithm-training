#include <bits/stdc++.h>
#define MAX_N 1'000'000
using namespace std;
typedef long long ll;

ll X;
ll is_prime[MAX_N];

void sieve() {
  fill(is_prime, is_prime + MAX_N, true);
  for (ll i = 2; i < MAX_N; ++i) {
    if (is_prime[i]) {
      for (ll j = i + i; j < MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  cin >> X;
  sieve();
  for (ll i = 2; i < MAX_N; ++i) {
    if (is_prime[i] && i >= X) {
      printf("%lld\n", i);
      return 0;
    }
  }
}