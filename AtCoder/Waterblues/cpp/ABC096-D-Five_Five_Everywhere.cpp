#include <bits/stdc++.h>
#define MAX_P 55'555
using namespace std;
typedef long long ll;

ll N;
bool is_prime[MAX_P + 1];

vector<ll> primes() {
  fill(is_prime, is_prime + MAX_P + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<ll> res;
  for (ll i = 2; i <= MAX_P; ++i) {
    if (is_prime[i]) {
      res.push_back(i);
      for (ll j = i + i; j <= MAX_P; j += i)
        is_prime[j] = false;
    }
  }
  return res;
}

int main() {
  cin >> N;
  vector<ll> ps = primes();
  vector<ll> end3;
  for (auto v : ps) {
    string s = to_string(v);
    if (s[s.size() - 1] == '3') end3.push_back(v);
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld%c", end3[i], i == N - 1 ? '\n' : ' ');
  }
}