#include <bits/stdc++.h>
#define MAX_Q 100'000
#define MAX_R 100'000
using namespace std;
typedef long long ll;

ll Q;
bool is_prime[MAX_R + 1];
ll sum[MAX_R + 2];

void init() {
  fill(is_prime, is_prime + (MAX_R + 1), true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_R; ++i) {
    if (is_prime[i]) {
      for (ll j = i + i; j <= MAX_R; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (ll i = 1; i <= MAX_R; ++i) {
    sum[i + 1] = sum[i] + (i % 2 != 0 && is_prime[i] && is_prime[(i + 1) / 2]);
  }
}

int main() {
  init();
  cin >> Q;
  ll L, R;
  vector<ll> res;
  for (ll _ = 0; _ < Q; ++_) {
    cin >> L >> R;
    res.push_back(sum[R + 1] - sum[L]);
  }
  for (auto x : res) {
    printf("%lld\n", x);
  }
}