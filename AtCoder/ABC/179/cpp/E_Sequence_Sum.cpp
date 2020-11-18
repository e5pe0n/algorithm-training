#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;

ll N, X, M;

int main() {
  cin >> N >> X >> M;
  vector<ll> ord(M, -1);
  vector<ll> rec, cyc;
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (ord[X] != -1) {
      for (ll j = ord[X]; j < i; ++j) {
        cyc.push_back(rec[j]);
      }
      break;
    }
    ord[X] = i;
    rec.push_back(X);
    res += X;
    X = X * X % M;
  }
  N -= rec.size();
  if (N == 0) {
    printf("%lld\n", res);
    return 0;
  }
  ll freq = cyc.size();
  vector<ll> sum(freq + 1, 0);
  for (int i = 0; i < freq; ++i) {
    sum[i + 1] = sum[i] + cyc[i];
  }
  ll q = N / freq;
  ll r = N % freq;
  res += sum[freq] * q + sum[r];
  printf("%lld\n", res);
}