#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string S;
  cin >> S;
  ll res = 0;
  ll cnt = 0;
  for (int i = S.size() - 1; i >= 0; --i) {
    if (S[i] == 'W') {
      ++cnt;
    } else {
      res += cnt;
    }
  }
  printf("%lld\n", res);
}