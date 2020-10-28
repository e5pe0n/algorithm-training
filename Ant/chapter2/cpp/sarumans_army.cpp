#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 1000

int N, R;
int X[MAX_N]{};

using namespace std;

int main() {
  ifstream ifs("../testset/sarumans_army/test1.txt");
  ifs >> N >> R;
  for (int i = 0; i < N; ++i) {
    ifs >> X[i];
  }
  sort(X, X + N);
  int i = 0, res = 0;
  while (i < N) {
    int s = X[i++];
    while (i < N && X[i] <= s + R) {
      ++i;
    }
    int p = X[i - 1];
    while (i < N && X[i] <= p + R) {
      ++i;
    }
    ++res;
  }
  printf("%d\n", res);
}