#include <bits/stdc++.h>
#define MAX_N 20
#define INF 4'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res |= A[i];
  }
  for (ll i = 1; i < N; ++i) {
    vector<ll> B(N - 1);
    for (ll j = 0; j < i; ++j) {
      B[j] = 1;
    }
    do {
      ll t = 0;
      ll sum = 0;
      for (ll j = 0; j < N; ++j) {
        t |= A[j];
        if (j < B.size() && B[j]) {
          sum ^= t;
          t = 0;
        }
      }
      sum ^= t;
      res = min(res, sum);
    } while (prev_permutation(B.begin(), B.end()));
  }
  printf("%lld\n", res);
}