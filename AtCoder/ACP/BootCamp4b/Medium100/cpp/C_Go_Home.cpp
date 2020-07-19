#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int X;
  cin >> X;
  int x = 0;
  int i = 1;
  while (x < X) {
    x += i++;
  }
  printf("%d\n", i - 1);
}
