#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, K;
ll X[3];
string T;
ll _T[MAX_N];
map<char, ll> idx{{'r', 0}, {'s', 1}, {'p', 2}};

void solve() {
  for (int i = 0; i < N; ++i) {
    _T[i] = idx[T[i]];
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    ll me = (_T[i] + 2) % 3;
    if (i - K < 0 || _T[i - K] != me) {
      res += X[me];
      _T[i] = me;
    } else {
      _T[i] = 4;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < 3; ++i) {
    cin >> X[i];
  }
  cin >> T;
  solve();
}