#include <iostream>
#include <stdint.h>

using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  while (N >= 0) {
    N -= 500;
  }

  if (N + 500 - A <= 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}