#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  ll N = S.size();
  ll i = 0;
  ll a = 0;
  ll res = 0;
  while (i < N) {
    if (S[i] == 'A') {
      ++a;
      ++i;
    } else if (S[i] == 'B' && S[i + 1] == 'C') {
      res += a;
      i += 2;
    } else {
      a = 0;
      ++i;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}