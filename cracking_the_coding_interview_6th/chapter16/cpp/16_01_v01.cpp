#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void swap(int &a, int &b) {
  b -= a;
  a += b;
  b *= -1;
  b += a;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int a, b;
  ifs >> a >> b;
  printf("%d %d\n", a, b);
  swap(a, b);
  printf("%d %d\n\n", a, b);
}

int main() {
  solve("../testcases/16_01/01.txt");
  solve("../testcases/16_01/02.txt");
  solve("../testcases/16_01/03.txt");
  solve("../testcases/16_01/04.txt");
}

// # ../testcases/16_01/01.txt
// 3 7
// 7 3

// # ../testcases/16_01/02.txt
// -3 -7
// -7 -3

// # ../testcases/16_01/03.txt
// -3 7
// 7 -3

// # ../testcases/16_01/04.txt
// 3 -7
// -7 3
