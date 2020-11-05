#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 4000

using namespace std;

typedef long long ll;

int n;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
ll CD[MAX_N];

int main() {
  ifstream ifs("../testset/4_values_whose_sum_is_0/test1.txt");
  ifs >> n;
  for (int i = 0; i < n; ++i) {
    ifs >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> B[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> C[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> D[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      CD[i * n + j] = C[i] + D[j];
    }
  }
  sort(CD, CD + n * n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ll cd = -(A[i] + B[j]);
      ans += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd); // num of CD[k] == cd
    }
  }
  printf("%lld\n", ans);
}