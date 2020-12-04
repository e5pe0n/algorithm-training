#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

void solve() {
  ll res;
  if (N % K == 0) {
    res = 0;
  } else {
    res = min(K - N % K, N % K);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}