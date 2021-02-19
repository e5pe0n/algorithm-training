#include <bits/stdc++.h>
#define MAX_N 300'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  if (K == 1) {
    printf("%lld\n", N);
    return 0;
  }
  ll cnt = 0;
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    if (A[i + 1] - A[i] > 0) {
      ++cnt;
      if (cnt + 1 >= K) ++res;
    } else {
      cnt = 0;
    }
  }
  printf("%lld\n", res);
}