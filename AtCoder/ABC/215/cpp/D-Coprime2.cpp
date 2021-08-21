#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll N, M;
ll A[MAX_N];
bool primes[MAX_N + 1];

void factorize(ll n) {
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) primes[i] = true;
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) primes[n] = true;
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    factorize(A[i]);
  }
  for (ll i = 2; i <= MAX_N; ++i) {
    if (primes[i]) {
      for (ll j = i + i; j <= MAX_N; j += i)
        primes[j] = true;
    }
  }
  vector<ll> res;
  for (ll i = 1; i <= M; ++i) {
    if (!primes[i]) res.push_back(i);
  }
  printf("%ld\n", res.size());
  for (auto r : res)
    printf("%lld\n", r);
}