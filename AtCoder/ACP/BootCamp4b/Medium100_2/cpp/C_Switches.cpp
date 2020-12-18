#include <bits/stdc++.h>
#define MAX_M 10
using namespace std;
typedef long long ll;

ll N, M;
vector<ll> S[MAX_M];
ll P[MAX_M];
ll C[MAX_M];

void solve() {
  ll res = 0;
  for (int i = 0; i < 1 << N; ++i) {
    ll cnt = 0;
    fill(C, C + N, 0LL);
    for (int j = 0; j < M; ++j) {
      for (auto s : S[j]) {
        if (i >> s & 1) {
          ++C[j];
        }
      }
      if (C[j] % 2 == P[j]) {
        ++cnt;
      }
    }
    if (cnt == M) {
      ++res;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    ll k;
    cin >> k;
    S[i] = vector<ll>(k);
    for (int j = 0; j < k; ++j) {
      cin >> S[i][j];
      --S[i][j];
    }
  }
  for (int i = 0; i < M; ++i) {
    cin >> P[i];
  }
  solve();
}