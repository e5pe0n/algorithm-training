#include <iostream>
#include <stdio.h>

using namespace std;

double Sx, Sy, Gx, Gy;

int main() {
  cin >> Sx >> Sy >> Gx >> Gy;
  double res = (Gx * Sy + Sx * Gy) / (Gy + Sy);
  printf("%.7f\n", res);
}