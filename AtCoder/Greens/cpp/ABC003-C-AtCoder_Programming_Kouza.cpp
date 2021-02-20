#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, K;
ll R[MAX_N];
bool used[MAX_N];

ll _pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) { res *= x; }
    x *= x;
    n >>= 1;
  }
  return res;
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> R[i];
  }
  sort(R, R + N);
  double C = 0;
  for (ll i = 0; i < K; ++i) {
    C = 0.5 * (C + R[N - K + i]);
  }
  printf("%.7f\n", C);
}