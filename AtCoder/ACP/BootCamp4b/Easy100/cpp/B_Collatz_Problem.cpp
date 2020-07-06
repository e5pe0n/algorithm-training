#include <iostream>
#include <stdio.h>

#define MAX_A 1'000'001

using namespace std;

bool A[MAX_A]{};

int f(int n) {
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

int main() {
  int s;
  cin >> s;
  int cnt = 1;
  A[s] = true;
  while (true) {
    s = f(s);
    ++cnt;
    if (A[s]) {
      printf("%d\n", cnt);
      return 0;
    } else {
      A[s] = true;
    }
  }
}