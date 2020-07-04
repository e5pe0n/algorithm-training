#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a * b) % 2 == 0) {
    printf("Even\n");
  } else {
    printf("Odd\n");
  }
}