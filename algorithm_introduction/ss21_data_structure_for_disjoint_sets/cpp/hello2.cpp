#include <stdio.h>

using namespace std;

struct El {
  int id;
};

El els[10];
El *K[6];

void print_el(El *x) {
  printf("\nprint_el");
  printf("x->id: %d\n", x->id);
}

void f(El *els, El **K) {
  printf("\nf\n");
  printf("els[0].id: %d\n", els[0].id);
  printf("K[0]->id: %d\n", K[0]->id);

  print_el(&els[0]);
  print_el(K[0]);
}

int main() {
  els[0] = El{0};
  els[1] = El{1};

  printf("els[0].id: %d\n", els[0].id);

  K[0] = &els[0];
  printf("K[0]->id: %d\n", K[0]->id);

  f(els, K);
}