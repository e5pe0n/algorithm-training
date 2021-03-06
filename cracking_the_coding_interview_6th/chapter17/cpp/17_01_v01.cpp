#include <fstream>
#include <string>
using namespace std;

int add(int a, int b) {
  int res = 0;
  int _c = 0;
  int i = 1;
  while (i != 0) {
    int s1 = (a & i) ^ (b & i);
    int c1 = (a & i) & (b & i);
    int s2 = s1 ^ _c;
    int c2 = s1 & _c;
    _c = c1 | c2;
    res |= s2;
    i <<= 1;
    _c <<= 1;
  }
  return res;
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