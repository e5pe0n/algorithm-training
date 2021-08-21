#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 10'000'000;
bool is_prime[N + 1];

vector<ll> gen_primes() {
  fill(is_prime, is_prime + N + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<ll> primes;
  for (ll i = 2; i <= N; ++i) {
    if (is_prime[i]) primes.push_back(i);
    for (ll j = i + i; j <= N; j += i)
      is_prime[j] = false;
  }
  return primes;
}

int main() {
  vector<ll> primes = gen_primes();
  printf("%ld\n", primes.size());
}