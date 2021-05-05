#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string d2bs(double n, int bits) {
  string res;
  while (bits--) {
    n *= 2;
    res += to_string(n >= 1);
    n -= n >= 1;
  }
  if (n != 0) return "ERROR";
  return res;
}

void solve(const string &fp) {
  ifstream ifs(fp);
  double n;
  ifs >> n;
  string res = d2bs(n, 32);
  puts(res.c_str());
}

int main() {
  solve("../testcases/05_02/01.txt");
  solve("../testcases/05_02/02.txt");
  solve("../testcases/05_02/03.txt");
}