#include <bits/stdc++.h>
#define MAX_N 80
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = 1000;
  for (ll i = 0; i < N - 1; ++i) {
    ll cnt = 0;
    if (A[i + 1] > A[i]) cnt = res / A[i];
    res += (A[i + 1] - A[i]) * cnt;
  }
  printf("%lld\n", res);
}