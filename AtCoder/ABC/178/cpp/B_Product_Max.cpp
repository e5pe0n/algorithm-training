#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;
  printf("%lld\n", max({a * c, a * d, b * c, b * d}));
}