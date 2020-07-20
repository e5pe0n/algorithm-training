#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int W, H, x, y;
  cin >> W >> H >> x >> y;
  printf("%f %d\n", 0.5 * W * H, W * 0.5 == x && H * 0.5 == y);
}