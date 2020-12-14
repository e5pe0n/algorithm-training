#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, T;
ll t[MAX_N];

void solve() {
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    res += min(T, t[i + 1] - t[i]);
  }
  res += T;
  printf("%lld\n", res);
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; ++i) {
    cin >> t[i];
  }
  solve();
}