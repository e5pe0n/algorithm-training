#include <bits/stdc++.h>
#define MAX_L 120
using namespace std;
typedef long long ll;

ll L;

void solve() {
  ll res = 1;
  for (int i = 1; i <= 11; ++i) {
    res = res * (L - i) / i;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> L;
  solve();
}
