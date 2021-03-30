#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  default_random_engine generator;
  uniform_int_distribution<ll> distribution(1, 6);
  for (ll i = 0; i < 10; ++i) {
    printf("%lld\n", distribution(generator));
  }
}
