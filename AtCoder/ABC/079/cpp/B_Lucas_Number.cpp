#include <iostream>
#include <stdio.h>

#define MAX_N 64

using namespace std;

int64_t L[MAX_N]{};

int64_t f(int i) {
  if (i == 0) {
    return 2;
  }
  if (i == 1) {
    return 1;
  }
  if (L[i] == 0) {
    L[i] = f(i - 1) + f(i - 2);
  }
  return L[i];
}

int main() {
  int N;
  cin >> N;
  printf("%lld\n", f(N));
}
