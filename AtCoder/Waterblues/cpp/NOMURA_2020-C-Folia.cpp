#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N + 1];
ll B[MAX_N + 2];

int main() {
  cin >> N;
  for (ll i = 0; i <= N; ++i)
    cin >> A[i];
  for (ll i = N; i >= 0; --i)
    B[i] = B[i + 1] + A[i];
  ll cnt = 1;
  ll res = 0;
  for (ll i = 0; i <= N; ++i) {
    res += cnt;
    cnt -= A[i];
    if (cnt < 0) {
      res = -1;
      break;
    }
    cnt = min(cnt * 2, B[i + 1]);
  }
  printf("%lld\n", res);
}