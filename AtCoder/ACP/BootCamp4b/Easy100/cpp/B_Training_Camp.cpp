#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  ll n = 1;
  for (int i = 1; i <= N; ++i) {
    n = (n * i) % (1'000'000'007);
  }
  printf("%lld\n", n);
}