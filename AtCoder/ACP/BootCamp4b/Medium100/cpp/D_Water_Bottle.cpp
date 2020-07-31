#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265359

using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double res;
  if (x <= 0.5 * a * a * b) {
    res = atan(2.0 * x / (a * b * b)) * 180 / PI;
  } else if (x < a * a * b) {
    res = atan(a / (2.0 * (b - x / (a * a)))) * 180 / PI;
  } else {
    res = 90.0;
  }
  printf("%.7f\n", 90 - res);
}