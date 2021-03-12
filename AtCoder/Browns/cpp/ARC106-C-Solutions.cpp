#include <bits/stdc++.h>
#define MAX_R 1'000'000'000
using namespace std;
typedef long long ll;

ll N, M;

void p(ll L, ll R) {
  printf("%lld %lld\n", L, R);
}

int main() {
  cin >> N >> M;
  ll L0 = 1, R0 = MAX_R;
  if (N == 1 && M == 0) {
    p(L0, R0);
    return 0;
  }
  if (!(0 <= M && M <= N - 2)) {
    puts("-1");
    return 0;
  }
  p(L0, R0);
  ll L = 2, R = 3;
  for (ll i = 0; i < M; ++i) {
    p(L, R);
    L = R + 1, R = L + 1;
  }
  R = R0 - 1;
  p(L, R);
  for (ll i = 0; i < N - M - 2; ++i) {
    p(++L, --R);
  }
}