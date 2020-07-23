#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int x_low = 0;
  int x_up = W;
  int y_low = 0;
  int y_up = H;
  for (int i = 0; i < N; ++i) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      x_low = max(x_low, x);
    } else if (a == 2) {
      x_up = min(x_up, x);
    } else if (a == 3) {
      y_low = max(y_low, y);
    } else {
      y_up = min(y_up, y);
    }
  }
  printf("%d\n", max(0, x_up - x_low) * max(0, y_up - y_low));
}