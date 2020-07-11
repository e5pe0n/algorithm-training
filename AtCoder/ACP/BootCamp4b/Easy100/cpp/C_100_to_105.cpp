#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int X;
  cin >> X;
  if (X >= (int)ceil((X % 100) / 5.0) * 100) {
    printf("1\n");
  } else {
    printf("0\n");
  }
}