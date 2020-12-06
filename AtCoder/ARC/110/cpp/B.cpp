#include <bits/stdc++.h>
#define M 10'000'000'000
using namespace std;
typedef long long ll;

ll N;
string T;

void solve() {
  ll res = 0;
  if (N == 1) {
    if (T == "1") {
      res = 2 * M;
    } else {
      res = M;
    }
  } else if (N == 2) {
    if (T == "11" || T == "10") {
      res = M;
    } else if (T == "01") {
      res = M - 1;
    }
  } else {
    string pre = T.substr(0, 3);
    if (pre == "110" || pre == "101" || pre == "011") {
      int j = 0;
      bool f = true;
      for (int i = 0; i < N; ++i) {
        if (T[i] != pre[(j++) % 3]) {
          f = false;
          break;
        }
      }
      if (f) {
        if (pre == "110") {
          res = M - N / 3 + (N % 3 == 0);
        } else {
          res = M - N / 3;
        }
      } else {
        res = 0;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> T;
  solve();
}