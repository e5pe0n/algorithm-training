#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
string S, T;

void solve() {
  if (N > M) {
    swap(N, M);
    swap(S, T);
  }
  ll g = __gcd(N, M);
  ll L = N * M / g;
  ll n = N / g;
  ll m = M / g;
  ll res = L;
  for (int i = 0; i < N; ++i) {
    if (i * m % n == 0 && i * m / n < M && S[i] != T[i * m / n]) {
      res = -1;
      break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M >> S >> T;
  solve();
}