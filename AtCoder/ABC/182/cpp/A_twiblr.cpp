#include <iostream>
#include <stdio.h>

using namespace std;

int A, B;

int main() {
  cin >> A >> B;
  int res = 2 * A + 100 - B;
  printf("%d\n", res);
}