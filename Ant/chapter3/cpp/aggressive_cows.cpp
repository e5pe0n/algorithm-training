#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100'000
#define INF 1'000'000'000

using namespace std;

int N, M;
int x[MAX_N];

bool C(int d) {
  int last = 0;
  for (int i = 1; i < M; ++i) {
    int crt = last + 1;
    while (crt < N && x[crt] - x[last] < d) {
      ++crt;
    }
    if (crt == N) {
      return false;
    }
    last = crt;
  }
  return true;
}

int main() {
  ifstream ifs("../testset/aggressive_cows/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> x[i];
  }
  sort(x, x + N);
  int lb = 0;
  int ub = INF;
  while (ub - lb > 1) {
    // Must be ub - lb > 1, not ub - lb >= 1.
    // If ub - lb = 1 and C(lb) is true, C(ub) is false.
    int mid = (ub + lb) / 2;
    if (C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%d\n", lb); // ub doesn't satisfy C(mid)
}