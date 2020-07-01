#include <bitset>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  bitset<8> a("00011011");
  bitset<8> b("00110101");

  auto c = a & b;
  printf("%s\n", c.to_string().c_str());        // 00010001
  printf("%s\n", (c << 1).to_string().c_str()); // 00100010
  printf("%s\n", (c << 2).to_string().c_str()); // 01000100
  printf("%s\n", (c >> 1).to_string().c_str()); // 00001000

  c <<= 4;
  printf("%s\n", c.to_string().c_str()); // 00010000

  c ^= bitset<8>("1101000");
  printf("%s\n", c.to_string().c_str()); // 01111000z

  printf("%lld\n", c.to_ullong()); // 120
}