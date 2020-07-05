#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int a = 1;
  int cnt = 0;
  while (a < B) {
    --a;
    a += A;
    ++cnt;
  }
  printf("%d\n", cnt);
}