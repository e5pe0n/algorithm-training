#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll NG[3];

int main() {
  cin >> N;
  for (ll i = 0; i < 3; ++i) {
    cin >> NG[i];
  }
  for (ll i = 0; i < 3; ++i) {
    if (N == NG[i]) {
      puts("NO");
      return 0;
    }
  }
  ll cnt = 100;
  while (N > 0 && cnt-- > 0) {
    for (ll i = 3; i >= 1; --i) {
      ll n = N - i;
      bool f = true;
      for (ll j = 0; j < 3; ++j) {
        if (n == NG[j]) {
          f = false;
          break;
        }
      }
      if (f) {
        N = n;
        break;
      }
    }
  }
  if (N > 0)
    puts("NO");
  else
    puts("YES");
}