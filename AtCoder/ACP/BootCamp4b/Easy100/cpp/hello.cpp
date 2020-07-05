#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int H32 = 1'000'000'000;
  int64_t H64 = 1'000'000'000;

  int res32_32_3 = H32 * 3;     // -1294967296
  int64_t res64_32_3 = H32 * 3; // -1294967296
  int64_t res64_64_3 = H64 * 3; // 3000000000
  int64_t res64_3_32 = 3 * H32; // -1294967296
  int64_t res64_3_64 = 3 * H64; // 3000000000
  printf("32_32_3: %d\n", res32_32_3);
  printf("64_32_3: %lld\n", res64_32_3);
  printf("64_64_3: %lld\n", res64_64_3);
  printf("64_3_32: %lld\n", res64_3_32);
  printf("64_3_64: %lld\n", res64_3_64);
}