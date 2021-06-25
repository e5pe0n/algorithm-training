// Crakinig the Coding Interview p.530
#include <fstream>
#include <string>
using namespace std;

int add(int a, int b) {
  if (b == 0) return a;
  int sum = a ^ b;
  int carry = (a & b) << 1;
  return add(sum, carry);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  int a, b;
  ifs >> a >> b;
  printf("%d + %d = %d\n", a, b, add(a, b));
  puts("");
}

int main() {
  solve("../testcases/17_01/01.txt");
  solve("../testcases/17_01/02.txt");
  solve("../testcases/17_01/03.txt");
  solve("../testcases/17_01/04.txt");
  solve("../testcases/17_01/05.txt");
  solve("../testcases/17_01/06.txt");
  solve("../testcases/17_01/07.txt");
}

// # ../testcases/17_01/01.txt
// 1 + 1 = 2

// # ../testcases/17_01/02.txt
// 78914 + 34889 = 113803

// # ../testcases/17_01/03.txt
// 1 + -1 = 0

// # ../testcases/17_01/04.txt
// 1 + -2 = -1

// # ../testcases/17_01/05.txt
// 789 + -123456 = -122667

// # ../testcases/17_01/06.txt
// -1 + -1 = -2

// # ../testcases/17_01/07.txt
// -78914 + -34889 = -113803