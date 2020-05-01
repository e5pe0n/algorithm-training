#include <stdio.h>

using namespace std;

enum Color { RED, BLACK };

int main() {
  bool b = Color::RED == 0;
  printf("%d\n", b);
}