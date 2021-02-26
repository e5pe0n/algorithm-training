#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  ll res = 0;
  ll f = true;
  for (ll i = 0; i < S.size() - 1; i += 2) {
    ll opr = S[i] - '0';
    char op = S[i + 1];
    if (op == '+') {
      res += (opr > 0) && f;
      f = true;
    } else {
      f &= opr > 0;
    }
  }
  res += (S[S.size() - 1] - '0' > 0) && f;
  printf("%lld\n", res);
}