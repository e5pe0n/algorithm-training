#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll res = 0;
  for (int i = 1; i <= N; ++i) {
    string s10;
    int n = i;
    while (n > 0) {
      s10 = to_string(n % 10) + s10;
      n /= 10;
    }
    n = i;
    string s8;
    while (n > 0) {
      s8 = to_string(n % 8) + s8;
      n /= 8;
    }
    bool f = true;
    for (auto s : s10) {
      if (s == '7') {
        f = false;
        break;
      }
    }
    for (auto s : s8) {
      if (s == '7') {
        f = false;
        break;
      }
    }
    if (f) {
      ++res;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}