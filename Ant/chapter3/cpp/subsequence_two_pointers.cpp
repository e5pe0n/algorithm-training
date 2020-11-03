#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int n, S;
int a[MAX_N];

int main() {
  ifstream ifs("../testset/subsequence/test2.txt");
  ifs >> n >> S;
  for (int i = 0; i < n; ++i) {
    ifs >> a[i];
  }
  int res = n + 1;
  int i = 0, j = 0, s = 0;
  for (;;) {
    while (j < n && s < S) {
      s += a[j++];
    }
    if (s < S) {
      break;
    }
    res = min(res, j - i);
    s -= a[i++];
  }
  if (res > n) {
    res = 0;
  }
  printf("%d\n", res);
}