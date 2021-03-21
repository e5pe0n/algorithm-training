#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  ll g = 0;
  ll p = 0;
  ll res = 0;
  for (ll i = 0; i < S.size(); ++i) {
    if (i % 2 == 0 && S[i] == 'p') --res;
    if (i % 2 != 0 && S[i] == 'g') ++res;
  }
  printf("%lld\n", res);
}