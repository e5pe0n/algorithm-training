#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  ll N = S.size();
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'U') {
      res += (N - i - 1) + (i)*2;
    }
  }
  ll d = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == 'D') {
      res += i + (N - i - 1) * 2;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}