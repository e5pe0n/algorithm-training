#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;

void solve() {
  if (K % 2 == 0 || K % 5 == 0) {
    printf("-1\n");
    return;
  }
  ll res = 0;
  ll t = 0;
  do {
    for (int i = 0; i <= 9; ++i) {
      t += K * i;
      if (t % 10 == 7) {
        ++res;
        t /= 10;
        break;
      }
      t -= K * i;
    }
  } while (t > 0);
  printf("%lld\n", res);
}

int main() {
  cin >> K;
  solve();
}