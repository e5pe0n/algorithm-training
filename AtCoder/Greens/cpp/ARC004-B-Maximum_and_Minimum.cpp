#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
typedef long long ll;

ll N;
ll D[MAX_N];

int main() {
  cin >> N;
  ll res_ma = 0;
  ll ma = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> D[i];
    res_ma += D[i];
    ma = max(ma, D[i]);
  }
  ll remain = res_ma - ma;
  ll res_mi = max(0LL, ma - remain);
  printf("%lld\n", res_ma);
  printf("%lld\n", res_mi);
}