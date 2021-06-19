#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 1e9;
ll N;

int main() {
  cin >> N;
  for (ll i = 1; i <= MAX_N; ++i) {
    if (i * (i + 1) >= N * 2) {
      printf("%lld\n", i);
      return 0;
    }
  }
}