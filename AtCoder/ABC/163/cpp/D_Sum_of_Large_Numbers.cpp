#include <bits/stdc++.h>
#define MAX_N 200'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, K;
ll asc[MAX_N + 2], dsc[MAX_N + 2];

void solve() {
  for (int i = 0; i <= N; ++i) {
    asc[i + 1] = asc[i] + i;
    dsc[i + 1] = dsc[i] + N - i;
  }
  ll res = 0;
  for (int k = K; k <= N + 1; ++k) {
    res = (res + dsc[k] - asc[k] + 1 + MOD) % MOD;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}