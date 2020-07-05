#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int H;
  int64_t W;
  cin >> H >> W;
  if (H == 1 || W == 1) {
    printf("1\n");
    return 0;
  }
  int a = (int)((W + 1) / 2);
  int64_t res = W * (int)(H / 2) + (H % 2) * a;
  printf("%lld\n", res);
}