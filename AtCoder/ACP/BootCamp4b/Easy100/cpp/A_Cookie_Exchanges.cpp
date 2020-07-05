#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if ((A % 2 != 0 || B % 2 != 0 || C % 2 != 0)) {
    printf("0\n");
    return 0;
  }
  if (A == B and B == C) {
    printf("-1\n");
    return 0;
  }

  int cnt = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    int _A = A;
    int _B = B;
    int _C = C;
    A = _B / 2 + _C / 2;
    B = _A / 2 + _C / 2;
    C = _A / 2 + _B / 2;
    ++cnt;
  }
  printf("%d\n", cnt);
}