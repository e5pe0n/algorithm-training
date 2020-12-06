#include <bits/stdc++.h>
#define MAX_N 30
using namespace std;
typedef long long ll;

ll N;
bool is_prime[MAX_N + 1];

void solve() {
  memset(is_prime, true, sizeof(is_prime));
  ll res = 1;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
      int j = i;
      while (j <= N) {
        j *= i;
      }
      res *= j / i;
    }
  }
  printf("%lld\n", res + 1);
}

int main() {
  cin >> N;
  solve();
}