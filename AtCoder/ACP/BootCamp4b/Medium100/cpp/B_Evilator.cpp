#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string S;
  cin >> S;
  ll res = 0;
  int N = S.size();
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'U') {
      res += (ll)N - 1 - i + 2 * i;
    } else {
      res += (ll)2 * (N - 1 - i) + i;
    }
  }
  printf("%lld\n", res);
}