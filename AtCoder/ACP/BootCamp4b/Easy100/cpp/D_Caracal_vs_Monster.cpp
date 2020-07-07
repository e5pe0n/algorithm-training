#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int64_t H;
  cin >> H;
  if (H == 1) {
    printf("1\n");
    return 0;
  }
  int64_t cnt = 1;
  int64_t i = 1;
  H /= 2;
  while (H > 0) {
    i <<= 1;
    cnt += i;
    H /= 2;
  }
  printf("%lld\n", cnt);
}
