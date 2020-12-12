#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll res = N * (N + 1) / 2 - N;
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}