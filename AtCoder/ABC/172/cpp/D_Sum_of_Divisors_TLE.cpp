#include <bits/stdc++.h>
#define MAX_N 10'000'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
bool is_prime[MAX_N + 1];
ll ns[MAX_N + 1];
ll cnt[MAX_N + 1];

vector<ll> enum_prime() {
  vector<ll> res;
  fill(is_prime, is_prime + N + 1, 1);
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      res.push_back(i);
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return res;
}

void solve() {
  vector<ll> primes = enum_prime();
  cnt[1] = 1;
  ns[0] = 1;
  ll end = 1;
  ll right = end;
  for (auto p : primes) {
    for (int left = 0; left < right; ++left) {
      ll x = p;
      int n = 1;
      while (ns[left] * x <= N) {
        ns[end++] = ns[left] * x;
        cnt[ns[end - 1]] = cnt[ns[left]] * (n++ + 1);
        x *= p;
      }
    }
    right = end;
  }
  ll res = 0;
  for (int i = 1; i <= N; ++i) {
    res += i * cnt[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}