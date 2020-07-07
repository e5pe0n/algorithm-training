#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll p = N / (A + B);
  ll q = N % (A + B);
  printf("%lld\n", A * p + min(A, q));
}