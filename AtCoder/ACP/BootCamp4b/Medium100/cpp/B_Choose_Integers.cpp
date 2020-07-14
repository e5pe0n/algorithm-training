#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (C % gcd(A, B) == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}