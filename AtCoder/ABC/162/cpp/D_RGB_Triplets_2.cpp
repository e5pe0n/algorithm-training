#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

void solve() {
  ll r = 0, b = 0, g = 0;
  for (int i = 0; i < N; ++i) {
    r += S[i] == 'R';
    b += S[i] == 'B';
    g += S[i] == 'G';
  }
  ll res = r * b * g;
  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 1; j + (j - i) < N; ++j) {
      if (S[i] != S[j] && S[j] != S[j + (j - i)] && S[j + (j - i)] != S[i]) {
        res -= 1;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}