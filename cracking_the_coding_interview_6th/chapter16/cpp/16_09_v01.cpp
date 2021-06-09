#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int neg(int a) {
  return ~a + 1;
}

int _sub(int a, int b) {
  return a + neg(b);
}

int _mul(int a, int b) {
  bool ng = (a < 0 && b > 0) || (a > 0 && b < 0);
  if (a < 0) a = neg(a);
  if (b < 0) b = neg(b);
  if (a < b) swap(a, b);
  int res = 0;
  while (b > 0) {
    if (b & 1) res += a;
    a <<= 1;
    b >>= 1;
  }
  return ng ? neg(res) : res;
}

int _div(int a, int b) {
  if (b == 0) throw invalid_argument{"zero division"};
  bool ng = (a < 0 && b > 0) || (a > 0 && b < 0);
  if (a < 0) a = neg(a);
  if (b < 0) b = neg(b);
  int res = 0;
  if (a < b) return 0;
  int mask = 1 << 30;
  int t = 1;
  while (b <= a && !(b & mask)) {
    t <<= 1;
    b <<= 1;
  }
  while (b > 0) {
    if (a >= b) {
      a = _sub(a, b);
      res += t;
    }
    t >>= 1;
    b >>= 1;
  }
  return ng ? neg(res) : res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int a, b;
  ifs >> a >> b;
  printf("%d - %d = %d\n", a, b, _sub(a, b));
  printf("%d * %d = %d\n", a, b, _mul(a, b));
  try {
    int d = _div(a, b);
    printf("%d / %d = %d\n", a, b, d);
  } catch (const invalid_argument &ia) { printf("%s\n", ia.what()); }
  puts("");
}

int main() {
  solve("../testcases/16_09/01.txt");
  solve("../testcases/16_09/02.txt");
  solve("../testcases/16_09/03.txt");
  solve("../testcases/16_09/04.txt");
  solve("../testcases/16_09/05.txt");
  solve("../testcases/16_09/06.txt");
  solve("../testcases/16_09/07.txt");
  solve("../testcases/16_09/08.txt");
  solve("../testcases/16_09/09.txt");
}

// # ../testcases/16_09/01.txt
// 20 - 5 = 15
// 20 * 5 = 100
// 20 / 5 = 4

// # ../testcases/16_09/02.txt
// 1 - 1 = 0
// 1 * 1 = 1
// 1 / 1 = 1

// # ../testcases/16_09/03.txt
// 1 - 0 = 1
// 1 * 0 = 0
// zero division

// # ../testcases/16_09/04.txt
// 0 - 1 = -1
// 0 * 1 = 0
// 0 / 1 = 0

// # ../testcases/16_09/05.txt
// -48 - 16 = -64
// -48 * 16 = -768
// -48 / 16 = -3

// # ../testcases/16_09/06.txt
// -48 - -16 = -32
// -48 * -16 = 768
// -48 / -16 = 3

// # ../testcases/16_09/07.txt
// -9 - 2 = -11
// -9 * 2 = -18
// -9 / 2 = -4

// # ../testcases/16_09/08.txt
// 9 - 2 = 7
// 9 * 2 = 18
// 9 / 2 = 4

// # ../testcases/16_09/09.txt
// 2147483647 - 2147483647 = 0
// 2147483647 * 2147483647 = 1
// 2147483647 / 2147483647 = 1
