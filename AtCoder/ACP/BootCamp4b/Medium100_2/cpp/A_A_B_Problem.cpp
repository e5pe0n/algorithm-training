#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B;

void solve() {
  ll res = max(0LL, (N - 1) * B + A - (B + (N - 1) * A) + 1);
  printf("%lld\n", res);
}

int main() {
  cin >> N >> A >> B;
  solve();
}