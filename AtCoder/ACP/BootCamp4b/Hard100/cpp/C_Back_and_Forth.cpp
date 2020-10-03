#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  printf("%c", 'L');
  for (int i = 0; i < ty - sy + 1; ++i) {
    printf("%c", 'U');
  }
  for (int i = 0; i < tx - sx + 1; ++i) {
    printf("%c", 'R');
  }
  for (int i = 0; i < ty - sy + 1; ++i) {
    printf("%c", 'D');
  }
  for (int i = 0; i < tx - sx; ++i) {
    printf("%c", 'L');
  }
  for (int i = 0; i < ty - sy; ++i) {
    printf("%c", 'U');
  }
  for (int i = 0; i < tx - sx + 1; ++i) {
    printf("%c", 'R');
  }
  for (int i = 0; i < ty - sy + 1; ++i) {
    printf("%c", 'D');
  }
  for (int i = 0; i < tx - sx + 1; ++i) {
    printf("%c", 'L');
  }
  printf("%c\n", 'U');
}