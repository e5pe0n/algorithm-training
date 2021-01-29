#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, K, M;
ll A[MAX_N];

void solve() {
  ll sum = 0;
  for (ll i = 0; i < N - 1; ++i) {
    sum += A[i];
  }
  ll res = M * N - sum;
  res = max(0LL, res);
  if (res > K) res = -1;
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K >> M;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> A[i];
  }
  solve();
}