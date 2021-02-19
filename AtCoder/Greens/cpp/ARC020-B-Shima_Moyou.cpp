#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, C;
ll A[MAX_N];

int main() {
  cin >> N >> C;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    --A[i];
  }
  ll res = INF;
  for (ll i = 0; i < 10; ++i) {
    for (ll j = 0; j < 10; ++j) {
      ll t = 0;
      if (i == j) continue;
      for (ll k = 0; k < N; ++k) {
        if (k % 2 == 0) {
          if (A[k] != i) t += C;
        } else {
          if (A[k] != j) t += C;
        }
      }
      res = min(res, t);
    }
  }
  printf("%lld\n", res);
}