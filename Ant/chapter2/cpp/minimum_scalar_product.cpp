#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_n 800

using namespace std;

typedef long long ll;

int n;
ll v1[MAX_n], v2[MAX_n];

int main() {
  ifstream ifs("../testset/minimum_scalar_product/test2.txt");
  ifs >> n;
  for (int i = 0; i < n; ++i) {
    ifs >> v1[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> v2[i];
  }
  sort(v1, v1 + n);
  sort(v2, v2 + n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += v1[i] * v2[n - 1 - i];
  }
  printf("%lld\n", ans);
}