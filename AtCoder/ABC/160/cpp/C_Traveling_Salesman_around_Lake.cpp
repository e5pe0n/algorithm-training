#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll K, N;
ll A[MAX_N];

void solve() {
  ll res = 0;
  ll max_d = 0;
  for (int i = 0; i < N; ++i) {
    ll d = (A[(i + 1) % N] - A[i] + K) % K;
    res += d;
    max_d = max(max_d, d);
  }
  res -= max_d;
  printf("%lld\n", res);
}

int main() {
  cin >> K >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}