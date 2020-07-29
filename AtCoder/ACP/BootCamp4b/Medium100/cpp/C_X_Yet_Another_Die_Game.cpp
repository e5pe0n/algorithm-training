#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll x;
  cin >> x;
  printf("%lld\n", (x / 11) * 2 + (ll)ceil((x % 11) / 6.0));
}