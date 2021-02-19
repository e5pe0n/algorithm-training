#include <bits/stdc++.h>
#define MAX_N 1'000'000
#define MOD 10'007
using namespace std;
typedef long long ll;

ll N;
ll d[MAX_N + 1];

int main() {
  cin >> N;
  d[3] = 1;
  for (ll i = 4; i <= N; ++i) {
    d[i] = (((d[i - 1] + d[i - 2]) % MOD) + d[i - 3]) % MOD;
  }
  printf("%lld\n", d[N]);
}