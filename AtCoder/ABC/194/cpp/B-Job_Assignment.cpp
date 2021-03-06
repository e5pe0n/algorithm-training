#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 1000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N], B[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  ll res = INF;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (i == j)
        res = min(res, A[i] + B[j]);
      else
        res = min(res, max(A[i], B[j]));
    }
  }
  printf("%lld\n", res);
}