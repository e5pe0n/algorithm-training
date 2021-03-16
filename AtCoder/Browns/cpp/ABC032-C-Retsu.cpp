#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, K;
ll S[MAX_N];

int main() {
  cin >> N >> K;
  bool f = false;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
    if (S[i] == 0) f = true;
  }
  if (f) {
    printf("%lld\n", N);
    return 0;
  }
  if (K == 0 && f == false) {
    puts("0");
    return 0;
  }
  ll left = 0, right = 0;
  ll t = 1;
  ll res = 0;
  while (right < N) {
    while (right < N && t * S[right] <= K) {
      t *= S[right++];
    }
    res = max(res, right - left);
    if (right - left == 0) break;
    if (right >= N) break;
    while (left < N && t * S[right] > K) {
      t /= S[left++];
    }
  }
  printf("%lld\n", res);
}