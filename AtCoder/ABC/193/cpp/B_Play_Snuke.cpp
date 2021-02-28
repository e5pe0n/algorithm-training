#include <bits/stdc++.h>
#define MAX_N 100'000
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  ll res = INF;
  for (ll i = 0; i < N; ++i) {
    ll A, P, X;
    cin >> A >> P >> X;
    if (X - A > 0) res = min(res, P);
  }
  if (res == INF) res = -1;
  printf("%lld\n", res);
}