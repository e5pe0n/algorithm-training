#include <bits/stdc++.h>
#define MAX_C 100
using namespace std;
typedef long long ll;

ll C;
vector<ll> V[MAX_C];

int main() {
  cin >> C;
  for (ll i = 0; i < C; ++i) {
    ll N, M, L;
    cin >> N >> M >> L;
    V[i] = vector<ll>{N, M, L};
    sort(V[i].begin(), V[i].end());
  }
  ll max_N = 0, max_M = 0, max_L = 0;
  for (ll i = 0; i < C; ++i) {
    max_N = max(max_N, V[i][0]);
    max_M = max(max_M, V[i][1]);
    max_L = max(max_L, V[i][2]);
  }
  printf("%lld\n", max_N * max_M * max_L);
}