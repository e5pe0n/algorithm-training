#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll i = 1; i * i < N; ++i) {
    if (N % i == 0 && N / i - 1 != i) {
      ans += N / i - 1;
    }
  }
  printf("%lld\n", ans);
}