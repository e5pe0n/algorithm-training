#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
const ll MOD = 1'000'000'007;
const string A = "atcoder";
ll N;
string S;
ll C[26];

int main() {
  map<char, char> prv_chars;
  for (ll i = 1; i < A.size(); ++i) {
    prv_chars[A[i]] = A[i - 1];
  }
  cin >> N >> S;
  for (ll i = 0; i < N; ++i) {
    if (S[i] == 'a')
      ++C[0];
    else
      C[S[i] - 'a'] = (C[S[i] - 'a'] + C[prv_chars[S[i]] - 'a']) % MOD;
  }
  printf("%lld\n", C['r' - 'a']);
}