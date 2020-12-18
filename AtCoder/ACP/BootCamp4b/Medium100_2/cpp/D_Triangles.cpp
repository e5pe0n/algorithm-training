#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;
typedef long long ll;

ll N;
ll L[MAX_N];

void solve() {
  sort(L, L + N);
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      ll t = lower_bound(L, L + N, L[i] + L[j]) - L - j - 1;
      res += max(0LL, t);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  solve();
}