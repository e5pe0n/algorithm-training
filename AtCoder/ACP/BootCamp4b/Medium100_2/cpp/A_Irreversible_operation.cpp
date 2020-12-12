#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  ll b = 0;
  ll res = 0;
  for (auto s : S) {
    if (s == 'B') {
      ++b;
    } else {
      res += b;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}