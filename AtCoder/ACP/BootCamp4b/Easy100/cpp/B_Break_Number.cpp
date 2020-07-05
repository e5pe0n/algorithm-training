#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int a = 1;
  while (a <= N) {
    a *= 2;
  }
  printf("%d\n", a / 2);
}
