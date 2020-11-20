#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int A, B;
  char op;
  cin >> A >> op >> B;
  if (op == '+') {
    printf("%d\n", A + B);
  } else {
    printf("%d\n", A - B);
  }
}