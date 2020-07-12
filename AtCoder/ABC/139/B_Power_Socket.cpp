#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int a = A;
  while (a < B) {
    a += A - 1;
  }
  printf("%d\n", a / A);
}