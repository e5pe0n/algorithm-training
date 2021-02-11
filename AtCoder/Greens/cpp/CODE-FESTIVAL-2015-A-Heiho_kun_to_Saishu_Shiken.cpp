#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, K, M, R;
ll S[MAX_N];

int main() {
  cin >> N >> K >> M >> R;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> S[i];
  }
  sort(S, S + N);
  ll sum = 0;
  for (ll i = N - K; i < N; ++i) {
    sum += S[i];
  }
  ll res;
  if (sum >= R * K)
    res = 0;
  else {
    res = R * K - (sum - S[N - K]);
    if (res > M) res = -1;
  }
  printf("%lld\n", res);
}