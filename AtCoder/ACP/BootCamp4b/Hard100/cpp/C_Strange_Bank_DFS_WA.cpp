// WA
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll N;

ll dfs(ll n, ll i) {
  if (n < 9) {
    return i + n / 6 + n % 6;
  }
  ll n6 = (ll)(log(n) / log(6));
  ll n9 = (ll)(log(n) / log(9));
  return min(dfs(n - (ll)pow(6, n6), i + 1), dfs(n - (ll)pow(9, n9), i + 1));
}

int main() {
  cin >> N;
  ll ans = dfs(N, 0);
  printf("%lld\n", ans);
}