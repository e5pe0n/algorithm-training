#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() {
  cin >> N >> S;
  ll res = 0;
  for (ll i = 0; i < N - 2; ++i) {
    if (S.substr(i, 3) == "ABC") ++res;
  }
  printf("%lld\n", res);
}