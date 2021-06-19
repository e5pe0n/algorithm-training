#include <fstream>
#include <string>
using namespace std;

int add(int a, int b) {
  int res = 0;
  int _c = 0;
  while (a > 0 || b > 0) {
    int s1 = (a & 1) ^ (b & 1);
    int c1 = (a & 1) & (b & 1);
    int s2 = s1 ^ _c;
    int c2 = s1 & _c;
    _c = c1 | c2;
    res |= s2;
    res <<= 1;
    a >>= 1;
    b >>= 1;
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
  
}