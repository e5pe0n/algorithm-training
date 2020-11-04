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
  for (int i = 0; _len + i < len; ++i) {
    res = "0" + res;
  }
  return res;
}

int main() {
  int sup = stoi("01101101", 0, 2);
  int sub = sup;
  do {
    // do something for sub
    printf("%s\n", d2b(sub, 8).c_str());
    sub = (sub - 1) & sup;
  } while (sub != sup);
}

// 01101101
// 01101100
// 01101001
// 01101000
// 01100101
// 01100100
// 01100001
// 01100000
// 01001101
// 01001100
// 01001001
// 01001000
// 01000101
// 01000100
// 01000001
// 01000000
// 00101101
// 00101100
// 00101001
// 00101000
// 00100101
// 00100100
// 00100001
// 00100000
// 00001101
// 00001100
// 00001001
// 00001000
// 00000101
// 00000100
// 00000001
// 00000000