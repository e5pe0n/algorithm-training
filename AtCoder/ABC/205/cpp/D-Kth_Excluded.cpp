#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100000;

ll N, Q;
ll A[MAX_N + 2];

int main() {
  cin >> N >> Q;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i + 1];
  }
  A[N + 1] = MAX_N + 1;
  vector<ll> sum(N + 1);
  for (ll i = 1; i <= N; ++i) {
    sum[i] = sum[i - 1] + A[i] - A[i - 1] - 1;
  }
  for (ll i = 0; i <= N; ++i) {
    printf("%lld%c", sum[i], i == N ? '\n' : ' ');
  }
  for (ll i = 0; i < Q; ++i) {
    ll K;
    cin >> K;
    auto it = lower_bound(sum.begin(), sum.end(), K);
    printf("%lld\n", K + (it - sum.begin()) - 1);
  }
}