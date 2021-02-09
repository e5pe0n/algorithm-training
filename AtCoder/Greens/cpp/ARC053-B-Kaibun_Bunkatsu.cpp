#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  map<char, ll> C;
  for (ll i = 0; i < S.size(); ++i) {
    ++C[S[i]];
  }
  ll odd = 0;
  ll even = 0;
  for (auto p : C) {
    odd += p.second % 2;
    even += p.second / 2;
  }
  ll res;
  if (odd == 0)
    res = S.size();
  else
    res = 1 + even / odd * 2;
  printf("%lld\n", res);
}