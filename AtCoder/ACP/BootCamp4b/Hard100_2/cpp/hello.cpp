#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N = 100'000;

int main() {
  ll n = 9;
  ll cnt = 0;
  while (n < N) {
    n *= 9;
    ++cnt;
  }
  printf("%lld, %lld\n", cnt, n);
}