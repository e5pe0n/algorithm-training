#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

int main() {
  cin >> N;
  ll k = 0;
  while (N >= 2) {
    ++k;
    N /= 2;
  }
  printf("%lld\n", k);
}