#include <bitset>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  bitset<4> A(2);
  bitset<4> B(7);
  bitset<4> C = A & B;
  printf("%s\n", C.to_string().c_str());
}