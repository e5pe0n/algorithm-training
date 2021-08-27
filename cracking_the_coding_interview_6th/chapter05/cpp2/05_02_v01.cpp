#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

string double2bit(double n, ll bits) {
  string res;
  while (bits--) {
    n *= 2;
    res += to_string(n >= 1);
    n -= (n >= 1);
  }
  if (n != 0) return "ERROR";
  return res;
}

void solve(const string &fp) {
  printf("%s\n", fp.c_str());
  ifstream ifs{fp};
  double n;
  ifs >> n;
  puts(double2bit(n, 32).c_str());
  puts("");
}

int main() {
  solve("../testcases/05_02/01.txt");
  solve("../testcases/05_02/02.txt");
  solve("../testcases/05_02/03.txt");
}