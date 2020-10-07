#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int64_t S;
  cin >> S;
  int s = (int)ceil(sqrt(S));
  int remain = s * s - S;
  int t = s;
  if (remain > s) {
    remain = s * (s - 1) - S;
    t = s - 1;
  }
  printf("%d %d %d %d %d %d\n", 0, 0, s, 1, remain, t);
}