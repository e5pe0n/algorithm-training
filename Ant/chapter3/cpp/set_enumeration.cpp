#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int n = 4;
  for (int i = 0; i < 1 << n; ++i) {
    string b;
    for (int j = n - 1; j >= 0; --j) {
      b += to_string(i >> j & 1);
    }
    printf("%s\n", b.c_str());
  }
}

// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111