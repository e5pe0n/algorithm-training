#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  if (N % 2 != 0) {
    printf("0\n");
    return 0;
  }
  N /= 10;
  ll cnt = 0;
  while (N > 0) {
    cnt += N;
    N /= 5;
  }
  printf("%lld\n", cnt);
}