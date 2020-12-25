#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  if (N % 2 != 0) {
    puts("0");
    return;
  }
  ll res = N /= 10;
  while (N > 0) {
    N /= 5;
    res += N;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}