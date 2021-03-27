#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() {
  cin >> N >> S;
  ll r = 0, g = 0, b = 0;
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] == 'R') ++r;
    if (S[i] == 'G') ++g;
    if (S[i] == 'B') ++b;
  }
  ll res = (r % 2) + (g % 2) + (b % 2);
  printf("%lld\n", res);
}