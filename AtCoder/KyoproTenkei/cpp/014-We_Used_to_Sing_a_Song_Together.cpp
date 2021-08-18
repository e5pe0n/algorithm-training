#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 100'000;
ll N;
ll A[MAX_N], B[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  sort(A, A + N);
  sort(B, B + N);
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += abs(A[i] - B[i]);
  }
  printf("%lld\n", res);
}