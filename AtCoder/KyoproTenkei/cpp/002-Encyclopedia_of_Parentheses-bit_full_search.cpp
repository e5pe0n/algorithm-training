#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

int main() {
  cin >> N;
  if (N % 2 != 0) return 0;
  for (ll i = 0; i < (1 << N); ++i) {
    ll sum = 0;
    string s;
    for (ll j = N - 1; j >= 0; --j) {
      if (i >> j & 1) {
        --sum;
        s += ')';
      } else {
        ++sum;
        s += '(';
      }
      if (sum < 0) break;
    }
    if (sum == 0) puts(s.c_str());
  }
}