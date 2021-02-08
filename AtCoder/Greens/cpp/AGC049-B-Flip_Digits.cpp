// WA: I cannot find what is wrong
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S, T;

int main() {
  cin >> N >> S >> T;
  vector<ll> VS;
  vector<ll> VT;
  for (ll i = N - 1; i >= 0; --i) {
    if (S[i] == '1') { VS.push_back(i); }
    if (T[i] == '1') { VT.push_back(i); }
    if (VS.size() < VT.size()) {
      puts("-1");
      return 0;
    }
  }
  if (VS.size() % 2 != VT.size() % 2) {
    puts("-1");
    return 0;
  }
  reverse(VS.begin(), VS.end());
  reverse(VT.begin(), VT.end());
  ll res = 0;
  ll j = 0;
  for (ll i = 0; i < VT.size(); ++i) {
    while (VS[j] < VT[i]) {
      res += VS[j + 1] - VS[j];
      j += 2;
    }
    res += VS[j] - VT[i];
    ++j;
  }
  printf("%lld\n", res);
}