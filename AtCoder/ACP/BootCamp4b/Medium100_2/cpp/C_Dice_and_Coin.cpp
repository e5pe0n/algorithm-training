#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;

ll pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

void solve() {
  double res = 0;
  for (int i = 1; i <= N; ++i) {
    int n = i;
    int cnt = 0;
    while (n < K) {
      n <<= 1;
      ++cnt;
    }
    res += 1 / (N * (double)pow(2, cnt));
  }
  printf("%.10f\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}