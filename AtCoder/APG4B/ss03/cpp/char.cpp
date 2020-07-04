#include <stdio.h>

using namespace std;

int main() {
  for (int i = 0; i <= ('Z' - 'A'); ++i) {
    printf("%c", 'A' + i);
  }
  printf("\n");
}