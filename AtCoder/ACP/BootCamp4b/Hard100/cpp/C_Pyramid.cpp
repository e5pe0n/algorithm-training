#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100

using namespace std;

struct Coord {
  int x, y, h;
};

int N;
Coord C[MAX_N]{};

int main() {
  cin >> N;
  int max_h = 0;
  for (int i = 0; i < N; ++i) {
    int x, y, h;
    cin >> x >> y >> h;
    C[i] = Coord{x, y, h};
    max_h = max(max_h, h);
  }
  for (int cx = 0; cx <= 100; ++cx) {
    for (int cy = 0; cy <= 100; ++cy) {
      for (int h = max_h; h <= max_h + 200; ++h) {
        bool determined = true;
        for (int i = 0; i < N; ++i) {
          if (max(h - abs(C[i].x - cx) - abs(C[i].y - cy), 0) != C[i].h) {
            determined = false;
            break;
          }
        }
        if (determined) {
          printf("%d %d %d\n", cx, cy, h);
          return 0;
        }
      }
    }
  }
}