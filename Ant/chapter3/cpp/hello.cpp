#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
  int A[] = {0, 1, 2, 3, 4};
  printf("%ld\n", lower_bound(A, A + 5, 10) - A);
}