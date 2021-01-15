#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;
string S1, S2;

void solve() {
  ll i = 0;
  ll res = 3;
  while (i < N) {
    if (S1[i] == S2[i]) {
      if (i - 1 >= 0 && S1[i - 1] == S2[i - 1]) { res = res * 2 % MOD; }
      ++i;
    } else {
      if (i - 1 >= 0 && S1[i - 1] != S2[i - 1]) {
        res = res * 3 % MOD;
      } else {
        res = res * 2 % MOD;
      }
      i += 2;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> S1 >> S2;
  solve();
}