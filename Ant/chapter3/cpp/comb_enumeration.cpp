#include <stdio.h>
#include <string>

using namespace std;

string d2b(int n, int len) {
  string res;
  while (n > 0) {
    if (n % 2 == 0) {
      res = "0" + res;
    } else {
      res = "1" + res;
    }
    n >>= 1;
  }
  int _len = res.size();
  for (int i = 0; i + _len < len; ++i) {
    res = "0" + res;
  }
  return res;
}

int main() {
  int k = 4;
  int n = 7;
  int comb = (1 << k) - 1;
  while (comb < 1 << n) {
    // do something for comb
    printf("%s\n", d2b(comb, n).c_str());
    int x = comb & -comb;
    int y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }
}

// 0001111
// 0010111
// 0011011
// 0011101
// 0011110
// 0100111
// 0101011
// 0101101
// 0101110
// 0110011
// 0110101
// 0110110
// 0111001
// 0111010
// 0111100
// 1000111
// 1001011
// 1001101
// 1001110
// 1010011
// 1010101
// 1010110
// 1011001
// 1011010
// 1011100
// 1100011
// 1100101
// 1100110
// 1101001
// 1101010
// 1101100
// 1110001
// 1110010
// 1110100
// 1111000