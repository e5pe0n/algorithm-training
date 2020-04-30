#include <stdio.h>

using namespace std;

int main() {
  for (int i = 1; i < 10; i += i) {
    printf("%d, ", i);
    printf("\n");
  }
}