#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;

int X1, X2, Y1, Y2, ans;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ifstream ifs("../testset/counting_lattice_points_on_a_line_segment/test1.txt");
  ifs >> X1 >> Y1 >> X2 >> Y2;
  int a = abs(X1 - X2);
  int b = abs(Y1 - Y2);
  ans = gcd(a, b) - 1;
  printf("%d\n", ans);
}