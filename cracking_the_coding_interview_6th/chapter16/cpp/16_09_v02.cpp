#include <fstream>
#include <string>
using namespace std;

// int neg(int a) {
//   int negated = 0;
//   int new_sign = a < 0 ? 1 : -1;
//   while (a != 0) {
//     negated += new_sign;
//     a += new_sign;
//   }
//   return negated;
// }

int neg(int a) {
  int negated = 0;
  int new_sign = a < 0 ? 1 : -1;
  int delta = new_sign;
  while (a != 0) {
    bool diff_sign = (a + delta > 0) != (a > 0);
    if (a + delta != 0 && diff_sign) delta = new_sign;
    negated += delta;
    a += delta;
    delta += delta;
  }
  return negated;
}

int _sub(int a, int b) {
  return a + neg(b);
}

int abs(int a) {
  return a < 0 ? neg(a) : a;
}

int _mul(int a, int b) {
  if (abs(a) < abs(b)) return _mul(b, a);
  int sum = 0;
  for (int i = abs(b); i > 0; i = _sub(i, 1)) {
    sum += a;
  }
  return b < 0 ? neg(sum) : sum;
}

int _div(int a, int b) {
  if (b == 0) throw invalid_argument{"zero division"};
  int abs_a = abs(a);
  int abs_b = abs(b);

  int product = 0;
  int x = 0;
  while (product + abs_b <= abs_a) {
    product += abs_b;
    ++x;
  }
  if ((a < 0 && b < 0) || (a > 0 && b > 0))
    return x;
  else
    return neg(x);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int a, b;
  ifs >> a >> b;
  printf("%d - %d = %d\n", a, b, _sub(a, b));
  printf("%d * %d = %d\n", a, b, _mul(a, b));
  try {
    printf("%d / %d = %d\n", a, b, _div(a, b));
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
  // solve("../testcases/16_09/09.txt");  // takes too long time
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
