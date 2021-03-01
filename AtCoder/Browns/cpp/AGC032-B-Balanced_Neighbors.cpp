#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
ll d[MAX_N][MAX_N];

int main() {
  cin >> N;
  ll cnt = 0;
  for (ll i = 1; i < N; ++i) {
    for (ll j = i + 1; j < N + 1; ++j) {
      if (N % 2 != 0 && i + j == N) continue;
      if (N % 2 == 0 && i + j == N + 1) continue;
      d[i - 1][j - 1] = true;
      ++cnt;
    }
  }
  printf("%lld\n", cnt);
  for (ll i = 0; i < N - 1; ++i) {
    for (ll j = i + 1; j < N; ++j) {
      if (d[i][j]) printf("%lld %lld\n", i + 1, j + 1);
    }
  }
}