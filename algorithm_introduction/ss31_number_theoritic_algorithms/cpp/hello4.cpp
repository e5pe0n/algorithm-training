#include <iostream>
#include <string>

using namespace std;

int main() {
  int a = 16;
  int u = a;
  int t = 0;
  while ((u & 1) != 1) {
    ++t;
    u = u >> 1;
  }

  cout << "t: " << to_string(t) << "\n";
  cout << "u: " << to_string(u) << "\n";
}