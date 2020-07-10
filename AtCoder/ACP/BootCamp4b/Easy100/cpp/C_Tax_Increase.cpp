#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int a = ceil(A / 0.08);
  int b = ceil(B / 0.1);
  if (a == b) {
    printf("%d\n", a);
  } else {
    if (a < b && (int)(b * 0.08) == A) {
      printf("%d\n", b);
    } else if (a > b && (int)(a * 0.1) == B) {
      printf("%d\n", a);
    } else {
      printf("-1\n");
    }
  }
}