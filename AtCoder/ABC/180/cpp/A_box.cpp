#include <iostream>
#include <stdio.h>

using namespace std;

int N, A, B;

int main() {
  cin >> N >> A >> B;
  int res = N - A + B;
  printf("%d\n", res);
}