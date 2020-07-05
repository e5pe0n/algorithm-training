#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int x = (int)(ceil(N / 1.08));
  if ((int)(x * 1.08) == N) {
    printf("%d\n", x);
  } else
    printf(":(\n");
}