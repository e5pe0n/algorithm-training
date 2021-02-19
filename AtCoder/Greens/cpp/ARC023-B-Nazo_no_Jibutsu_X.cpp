#include <bits/stdc++.h>
#define MAX_R 1000
#define MAX_C 1000
using namespace std;
typedef long long ll;

ll R, C, D;
ll A[MAX_R][MAX_C];

int main() {
  cin >> R >> C >> D;
  for (ll i = 0; i < R; ++i) {
    for (ll j = 0; j < C; ++j) {
      cin >> A[i][j];
    }
  }
  ll res = 0;
  for (ll i = 0; i <= min(D, R - 1); ++i) {
    for (ll j = 0; j <= min(D - i, C - 1); ++j) {
      if ((i + j) % 2 == (D % 2)) res = max(res, A[i][j]);
    }
  }
  printf("%lld\n", res);
}