#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  vector<ll> V;
  ll i = 0;
  ll cnt = 0;
  while (i < S.size()) {
    if (S.substr(i, 2) == "25") {
      ++cnt;
      i += 2;
    } else {
      if (cnt > 0) V.push_back(cnt);
      cnt = 0;
      ++i;
    }
  }
  if (cnt > 0) V.push_back(cnt);
  ll res = 0;
  for (auto v : V) {
    res += v * (v + 1) / 2;
  }
  printf("%lld\n", res);
}