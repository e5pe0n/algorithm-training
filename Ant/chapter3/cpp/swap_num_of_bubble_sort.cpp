#include <fstream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int N;
int B[MAX_N + 1];

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += B[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= N) {
    B[i] += x;
    i += i & -i;
  }
}

int main() {
  ifstream ifs("../testset/swap_num_of_bubble_sort/test1.txt");
  ifs >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    ifs >> x;
    ans += i - sum(x);
    add(x, 1);
  }
  printf("%d\n", ans);
}