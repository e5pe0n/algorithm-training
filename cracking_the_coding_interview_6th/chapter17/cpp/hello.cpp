#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  default_random_engine generator(100000000);
  for (ll i = 0; i < 10; ++i) {
    uniform_int_distribution<ll> distribution(0, 10);
    printf("%lld\n", distribution(generator));
  }
}