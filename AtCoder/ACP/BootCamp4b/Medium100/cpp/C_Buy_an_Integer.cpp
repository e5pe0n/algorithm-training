#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

#define MAX_N 1'000'000'000

typedef long long ll;

using namespace std;

int main() {
  ll A, B, X;
  cin >> A >> B >> X;
  int M = to_string(min(X, (ll)MAX_N)).size();
  ll res = 0;
  for (int i = M; i > 0; --i) {
    ll t = (X - B * i) / A;
    if (1 <= t && i <= to_string(t).size()) {
      res = max(res, min(t, i == to_string(MAX_N).size() ? (ll)MAX_N : (ll)pow(10, i) - 1));
    }
  }
  printf("%lld\n", res);
}