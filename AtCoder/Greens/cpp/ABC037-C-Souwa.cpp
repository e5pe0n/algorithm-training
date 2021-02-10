#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, K;
ll sum[MAX_N + 1];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    sum[i + 1] = sum[i] + A;
  }
  ll res = 0;
  for (ll i = 0; i < N - K + 1; ++i) {
    res += sum[i + K] - sum[i];
  }
  printf("%lld\n", res);
}