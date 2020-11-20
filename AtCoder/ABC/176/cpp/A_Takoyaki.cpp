#include <iostream>
#include <stdio.h>

using namespace std;

int N, X, T;

int main() {
  cin >> N >> X >> T;
  printf("%d\n", ((N - 1) / X + 1) * T);
}