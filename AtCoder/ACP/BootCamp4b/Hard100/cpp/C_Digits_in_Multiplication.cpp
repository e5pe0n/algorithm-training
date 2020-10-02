#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;

  ll ans = N;
  for (ll i = (ll)sqrt(N) + 1; i > 0; --i) {
    if (N % i == 0) {
      ans = N / i;
      break;
    }
  }
  printf("%lld\n", (ll)to_string(ans).size());
}