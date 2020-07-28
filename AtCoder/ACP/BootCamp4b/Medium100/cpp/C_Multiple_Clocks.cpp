#include <iostream>
#include <stdio.h>

#define MAX_N 100

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
  int N;
  cin >> N;
  ll res;
  cin >> res;
  for (int i = 1; i < N; ++i) {
    ll t;
    cin >> t;
    res = res * (t / gcd(res, t));
  }
  printf("%lld\n", res);
}