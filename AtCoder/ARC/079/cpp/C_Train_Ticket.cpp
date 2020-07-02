#include <bitset>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int a[4] = {s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0'};

  for (int i = 0; i < (1 << 3); ++i) {
    bitset<3> b(i);
    int t = a[0];
    string u(1, s[0]);
    for (int j = 0; j < 3; ++j) {
      if (b.test(j)) {
        t += a[j + 1];
        u += "+" + string(1, s[j + 1]);
      } else {
        t -= a[j + 1];
        u += "-" + string(1, s[j + 1]);
      }
    }
    if (t == 7) {
      printf("%s\n", (u + "=7").c_str());
      return 0;
    }
  }
}
