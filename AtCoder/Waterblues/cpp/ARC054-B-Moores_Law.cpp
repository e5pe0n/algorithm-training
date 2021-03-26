#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld P;
const ld MIN_X = 0;
const ld MAX_X = 1e9;

ld ternary_search(const function<ld(ld)> &f, ld left, ld right, ll iter) {
  while (iter--) {
    ld left_third = left + (right - left) / 3;
    ld right_third = right - (right - left) / 3;

    if (f(left_third) > f(right_third))
      left = left_third;
    else
      right = right_third;
  }
  return (right + left) / 2;
}

int main() {
  cin >> P;
  auto f = [](ld x) { return x + P / pow(2, x / 1.5); };
  ld x = ternary_search(f, MIN_X, MAX_X, 500);
  printf("%.9Lf\n", f(x));
}