#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const string T = "chokudai";
string S;

int main() {
  map<char, ll> c2i;
  for (ll i = 0; i < T.size(); ++i) {
    c2i[T[i]] = i;
  }
  cin >> S;
  map<char, ll> C;
  for (auto c : S) {
    if (c2i.find(c) == c2i.end()) continue;
    if (c == 'c') {
      ++C[c];
      continue;
    }
    char prv = T[c2i[c] - 1];
    C[c] = (C[c] + C[prv]) % MOD;
  }
  printf("%lld\n", C['i']);
}