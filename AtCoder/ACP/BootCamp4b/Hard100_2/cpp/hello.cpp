#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
  if (n < 2) {
    return 1;
  }
  return n * f(n - 2);
}

int main() {
  for (int i = 0; i <= 1000; ++i) {
    printf("(%d) %lld\n", i, f(i));
  }
}