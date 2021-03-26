#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
string S[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    ll last = -1;
    for (ll j = 0; j < N; ++j) {
      if (S[i][j] == '.') last = j;
    }
    if (last < 0) continue;
    for (ll j = 0; j <= last; ++j) {
      S[i][j] = 'o';
    }
    for (ll j = last; j < N; ++j) {
      if (i + 1 < N) S[i + 1][j] = 'o';
    }
    ++res;
  }
  printf("%lld\n", res);
}