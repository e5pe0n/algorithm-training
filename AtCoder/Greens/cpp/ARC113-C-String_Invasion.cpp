#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  ll N = S.size();
  map<char, ll> C;
  ll res = 0;
  for (ll i = N - 1; i > 0; --i) {
    ll cnt = 1;
    if (S[i - 1] == S[i]) {
      for (auto p : C) {
        if (p.first != S[i]) {
          res += p.second;
          cnt += p.second;
          C[p.first] = 0;
        }
      }
    }
    C[S[i]] += cnt;
  }
  printf("%lld\n", res);
}