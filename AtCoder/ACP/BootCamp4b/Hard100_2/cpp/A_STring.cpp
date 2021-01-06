#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string X;

void solve() {
  ll s = 0;
  ll cnt = 0;
  for (auto x : X) {
    if (x == 'S')
      ++s;
    else {
      if (s > 0) {
        --s;
        ++cnt;
      }
    }
  }
  ll res = X.size() - cnt * 2;
  printf("%lld\n", res);
}

int main() {
  cin >> X;
  solve();
}