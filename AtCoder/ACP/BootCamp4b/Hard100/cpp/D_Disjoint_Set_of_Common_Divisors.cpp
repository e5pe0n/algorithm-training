#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

vector<ll> factorize(ll n) {
  vector<ll> V{1};
  if (n == 1) {
    return V;
  }
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      V.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    V.push_back(n);
  }
  return V;
}

int main() {
  ll A, B;
  cin >> A >> B;
  vector<ll> V;
  printf("%lld\n", gcd(A, B));
  V = factorize(gcd(A, B));
  printf("%d\n", (int)V.size());
}