#include <iostream>
#include <stdio.h>

using namespace std;

int x;

int main() {
  cin >> x;
  printf("%d\n", x >= 0 ? x : 0);
}