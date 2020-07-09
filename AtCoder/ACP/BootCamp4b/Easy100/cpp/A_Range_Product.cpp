#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  if (0 < a || (b < 0 && (b - a) % 2 == 1)) {
    printf("Positive\n");
  } else if (a <= 0 && 0 <= b) {
    printf("Zero\n");
  } else {
    printf("Negative\n");
  }
}