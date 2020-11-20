#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  printf("%d\n", min(A * N, B));
}