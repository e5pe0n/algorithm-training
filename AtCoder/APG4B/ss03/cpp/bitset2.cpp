#include <bitset>
#include <stdio.h>

using namespace std;

int main() {
  bitset<4> d;
  d.set(0, 1);
  printf("%s\n", d.to_string().c_str()); // 0001
  printf("%d\n", d.test(0));             // 1
  printf("%d\n", d.test(3));             // 0

  d.set();
  printf("%s\n", d.to_string().c_str()); // 1111

  d.reset();
  printf("%s\n", d.to_string().c_str()); // 0000;

  bitset<4> f(5);                 // 0101
  printf("%d\n", (int)f.count()); // 2
  f.flip();
  printf("%s\n", f.to_string().c_str()); // 1010

  f.flip(0);
  printf("%s\n", f.to_string().c_str()); // 1011

  printf("%d\n", f.all()); // 0
  f.set();
  printf("%d\n", f.all()); // 1

  f.set(0, 0);
  printf("%d\n", f.any()); // 1
  f.reset();
  printf("%d\n", f.any()); // 0
}