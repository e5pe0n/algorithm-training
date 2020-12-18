#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

void solve() {
  ll _p = (ll)pow(2, M);
  ll res = (100 * (N - M) + 1900 * M) * _p;
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  solve();
}