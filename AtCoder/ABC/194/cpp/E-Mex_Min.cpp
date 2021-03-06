#include <bits/stdc++.h>
#define MAX_N 1'500'000
using namespace std;
typedef long long ll;

ll N, M;
vector<ll> P[MAX_N + 1];

int main() {
  for (ll i = 0; i <= MAX_N; ++i) {
    P[i].push_back(0);
  }
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    P[A].push_back(i + 1);
  }
  for (ll i = 0; i <= MAX_N; ++i) {
    P[i].push_back(N + 1);
  }
  for (ll i = 0; i <= MAX_N; ++i) {
    for (ll j = 0; j < P[i].size() - 1; ++j) {
      if (P[i][j + 1] - P[i][j] > M) {
        printf("%lld\n", i);
        return 0;
      }
    }
  }
}
