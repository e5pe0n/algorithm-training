#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll P[MAX_N];

void solve() {
  ll min_p = MAX_N + 1;
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (P[i] <= min_p) {
      ++res;
      min_p = P[i];
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> P[i];
  }
  solve();
}