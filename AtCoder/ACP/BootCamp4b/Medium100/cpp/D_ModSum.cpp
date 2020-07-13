#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  printf("%lld\n", (N - 1) * N / 2);
}