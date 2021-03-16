#include <bits/stdc++.h>
#define NS 10'000'000'000 * 3
using namespace std;
typedef long long ll;

ll N;
string T;
string s = "110";

int main() {
  cin >> N >> T;
  ll n = T.size();
  ll res = 0;
  if (n == 1) {
    if (T == "1")
      res = (NS / 3) * 2;
    else
      res = NS / 3;
  } else if (n == 2) {
    if (T == "11")
      res = NS / 3;
    else if (T == "10")
      res = NS / 3;
    else if (T == "01")
      res = NS / 3 - 1;
    else {
      puts("0");
      return 0;
    }
  } else {
    string pre = T.substr(0, 3);
    ll t = 0;
    if (pre == "110")
      t = 0;
    else if (pre == "101")
      t = 1;
    else if (pre == "011")
      t = 2;
    else {
      puts("0");
      return 0;
    }
    for (ll i = 0; i < n; ++i) {
      if (T[i] != s[(i + t) % 3]) {
        puts("0");
        return 0;
      }
    }
    if (t == 0)
      res = NS / 3 - (n + 3 - 1) / 3 + 1;
    else if (t == 1)
      res = NS / 3 - (n / 3 + 1) + 1;
    else
      res = NS / 3 - (n + 4) / 3 + 1;
  }
  printf("%lld\n", res);
}