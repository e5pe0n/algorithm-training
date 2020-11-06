#include <fstream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int N;
int B[MAX_N + 1];

int sum(int i) {
  // return sum of vals in [0, i]
  int s = 0;
  while (i > 0) {
    s += B[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int diff) {
  while (i <= N) {
    B[i] += diff;
    i += i & -i;
  }
}

int main() {
  ifstream ifs("../testset/binary_indexed_tree/test1.txt");
  ifs >> N;
  for (int i = 1; i <= N; ++i) {
    int b;
    ifs >> b;
    add(i, b);
  }
  printf("%d\n", sum(7)); // 35
  printf("%d\n", sum(4)); // 24
  printf("%d\n", sum(1)); // 5
}