#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, A, B;
ll X[MAX_N];

void solve() {
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    res += min((X[i + 1] - X[i]) * A, B);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> A >> B;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i];
  }
  solve();
}