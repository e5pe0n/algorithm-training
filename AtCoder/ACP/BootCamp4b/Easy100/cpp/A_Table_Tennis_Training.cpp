#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll res = 0;
  if (A % 2 == B % 2) {
    res = (B - A) / 2;
  } else {
    res = min((ll)((A + B) / 2), (ll)((N - A + 1 + N - B + 1) / 2));
  }
  printf("%lld\n", res);
}