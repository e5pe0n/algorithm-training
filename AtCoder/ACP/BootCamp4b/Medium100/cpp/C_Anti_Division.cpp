#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  ll Bc = B / C;
  ll Bd = B / D;
  ll Ac = (A - 1) / C;
  ll Ad = (A - 1) / D;
  ll lcm = C * (D / gcd(C, D));
  ll Blcm = B / lcm;
  ll Alcm = (A - 1) / lcm;
  printf("%lld\n", (B - A + 1) - ((Bc - Ac) + (Bd - Ad) - (Blcm - Alcm)));
}