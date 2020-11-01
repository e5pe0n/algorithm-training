#include <fstream>
#include <stdio.h>

using namespace std;

int a, b, x, y;

int extgcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main() {
  ifstream ifs("../testset/sugoroku/test1.txt");
  ifs >> a >> b;
  int res = extgcd(a, b, x, y);
  if (res != 1) {
    printf("-1\n");
  } else {
    if (x >= 0) {
      printf("%d 0 ", x);
    } else {
      printf("0 %d ", -x);
    }
    if (y >= 0) {
      printf("%d 0\n", y);
    } else {
      printf("0 %d\n", -y);
    }
  }
}