#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int t = 1900 * M + 100 * (N - M);
  printf("%d\n", t * (int)pow(2, M));
}