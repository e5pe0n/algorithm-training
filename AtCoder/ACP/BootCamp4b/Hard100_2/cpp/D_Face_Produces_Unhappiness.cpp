#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
string S;

void solve() {
  if (S[0] == 'R') {
    for (ll i = 0; i < N; ++i) {
      if (S[i] == 'L') {
        S[i] = 'R';
      } else {
        S[i] = 'L';
      }
    }
  }
  ll i = 0;
  while (i < N && K) {
    bool f = false;
    while (i < N && S[i] == 'R' && K) {
      S[i++] = 'L';
      f = true;
    }
    K -= f;
    while (i < N && S[i] == 'L') {
      ++i;
    }
  }
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    if ((S[i + 1] == 'L' && S[i] == 'L') || (S[i + 1] == 'R' && S[i] == 'R')) ++res;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K >> S;
  solve();
}