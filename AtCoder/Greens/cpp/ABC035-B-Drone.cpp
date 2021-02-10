#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll T;

int main() {
  cin >> S >> T;
  ll h = 0, w = 0, q = 0;
  for (auto s : S) {
    if (s == 'U')
      ++h;
    else if (s == 'D')
      --h;
    else if (s == 'R')
      ++w;
    else if (s == 'L')
      --w;
    else
      ++q;
  }
  ll res = 0;
  if (T == 2) {
    res = abs(h) + abs(w) - q;
    if (res < 0) res = abs(res) % 2;
  } else {
    res = abs(h) + abs(w) + q;
  }
  printf("%lld\n", res);
}