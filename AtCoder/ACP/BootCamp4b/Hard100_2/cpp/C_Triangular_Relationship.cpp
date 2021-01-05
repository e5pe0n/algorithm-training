#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

void solve() {
  ll res = (ll)pow(N / K, 3);
  if (K % 2 == 0 && N >= K / 2) { res += (ll)pow((N + (K / 2)) / K, 3); }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}