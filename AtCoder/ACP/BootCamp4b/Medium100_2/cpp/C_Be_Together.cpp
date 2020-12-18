#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll res = INF;
  for (int i = -100; i <= 100; ++i) {
    ll t = 0;
    for (int j = 0; j < N; ++j) {
      t += (i - A[j]) * (i - A[j]);
    }
    res = min(res, t);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}