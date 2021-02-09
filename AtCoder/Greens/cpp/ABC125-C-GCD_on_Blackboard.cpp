#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll G1[MAX_N + 1];
ll G2[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  G1[0] = A[0];
  G2[N] = A[N - 1];
  for (ll i = 0; i < N; ++i) {
    G1[i + 1] = __gcd(G1[i], A[i]);
    G2[N - i - 1] = __gcd(G2[N - i], A[N - i - 1]);
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (i == 0) {
      res = max(res, G2[i + 1]);
    } else if (i == N - 1) {
      res = max(res, G1[i]);
    } else {
      res = max(res, __gcd(G1[i], G2[i + 1]));
    }
  }
  printf("%lld\n", res);
}