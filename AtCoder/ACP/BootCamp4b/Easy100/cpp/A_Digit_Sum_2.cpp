#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string N;
  cin >> N;
  ll res = 0;
  for (int i = 0; i < N.size(); ++i) {
    res += N[i] - '0';
  }
  res = max(res, (ll)(max(0, N[0] - '0' - 1) + 9 * (N.size() - 1)));
  for (int i = 1; i < N.size() - 1; ++i) {
    if (N[i] - '0' > 0) {
      ll t = 0;
      for (int j = 0; j < i; ++j) {
        t += N[j] - '0';
      }
      t += N[i] - '0' - 1 + 9 * (N.size() - i - 1);
      res = max(res, t);
    }
  }
  printf("%lld\n", res);
}