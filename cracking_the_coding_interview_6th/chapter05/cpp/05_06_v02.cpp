// Cracking the Coding Interview p.286
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int cnt_flips(const int &n, const int &m) {
  int xored = n ^ m;
  int res = 0;
  while (xored) {
    xored = xored & (xored - 1);
    ++res;
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int n, m;
  ifs >> n >> m;
  cout << cnt_flips(n, m) << '\n' << endl;
}

int main() {
  solve("../testcases/05_06/01.txt");
  solve("../testcases/05_06/02.txt");
  solve("../testcases/05_06/03.txt");
  solve("../testcases/05_06/04.txt");
}

// # ../testcases/05_06/01.txt
// 2

// # ../testcases/05_06/02.txt
// 9

// # ../testcases/05_06/03.txt
// 5

// # ../testcases/05_06/04.txt
// 12
