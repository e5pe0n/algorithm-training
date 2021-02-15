#include <bits/stdc++.h>
#define MAX_N 5
#define MAX_K 5
using namespace std;
typedef long long ll;

ll N, K;
ll T[MAX_N][MAX_K];

bool dfs(ll i, ll x) {
  if (i == N) return x == 0;
  bool res = 0;
  for (ll k = 0; k < K; ++k) {
    res |= dfs(i + 1, x ^ T[i][k]);
  }
  return res;
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < K; ++j) {
      cin >> T[i][j];
    }
  }
  if (dfs(0, 0))
    puts("Found");
  else
    puts("Nothing");
}