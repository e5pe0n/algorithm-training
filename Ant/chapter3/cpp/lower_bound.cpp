#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_n 1'000'000

using namespace std;

int n, k;
int a[MAX_n];

int main() {
  ifstream ifs("../testset/lower_bound/test3.txt");
  ifs >> n >> k;
  for (int i = 0; i < n; ++i) {
    ifs >> a[i];
  }
  int ans = k <= a[n - 1] ? lower_bound(a, a + n, k) - a : n;
  printf("%d\n", ans);
}