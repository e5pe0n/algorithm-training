#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int toggle_bit(int n, int i) {
  return n ^ (1 << i);
}

int get_next(int n) {
  if (n == 0) return 1;
  int m = 1;
  int i = 0;
  while (!(n & m)) {
    m <<= 1;
    ++i;
  }
  cout << i << endl;
  n = toggle_bit(n, i);
  m <<= 1;
  ++i;
  while (n & m) {
    m <<= 1;
    ++i;
  }
  cout << i << endl;
  return toggle_bit(n, i);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int n;
  ifs >> n;
  bitset<32> before(n);
  bitset<32> nxt(get_next(n));
  cout << before << " -> " << nxt << '\n' << endl;
}

int main() {
  solve("../testcases/05_04/01.txt");
  solve("../testcases/05_04/02.txt");
  solve("../testcases/05_04/03.txt");
  solve("../testcases/05_04/04.txt");
}