#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

string i2s(ll x) {
  string res = to_string(x);
  ll n = res.size();
  for (int i = 0; n + i < 3; ++i) {
    res = '0' + res;
  }
  return res;
}

void solve() {
  ll res = 0;
  for (int i = 0; i < 1000; ++i) {
    string n = i2s(i);
    int idx = 0;
    for (auto s : S) {
      if (s == n[idx]) {
        ++idx;
        if (idx >= 3) {
          break;
        }
      }
    }
    if (idx >= 3) {
      ++res;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}