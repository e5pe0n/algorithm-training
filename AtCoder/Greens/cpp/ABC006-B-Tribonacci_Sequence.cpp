#include <bits/stdc++.h>
#define MAX_N 1'000'000
#define MOD 10'007
using namespace std;
typedef long long ll;

ll N;
ll memo[MAX_N + 1];

ll f(ll n) {
  if (n == 1 || n == 2) return 0;
  if (n == 3) return 1;
  if (memo[n] > 0) return memo[n];
  return memo[n] = ((f(n - 1) + f(n - 2)) % MOD + f(n - 3)) % MOD;
}

int main() {
  cin >> N;
  printf("%lld\n", f(N));
}