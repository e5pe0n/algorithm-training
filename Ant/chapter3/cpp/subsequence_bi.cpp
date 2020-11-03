#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int n, S;
int a[MAX_N], s[MAX_N + 1];

int main() {
  ifstream ifs("../testset/subsequence/test1.txt");
  ifs >> n >> S;
  for (int i = 0; i < n; ++i) {
    ifs >> a[i];
    s[i + 1] = s[i] + a[i];
  }
  if (s[n] < S) {
    printf("0\n");
    return 0;
  }
  int ans = n;
  for (int i = 0; s[i] + S <= s[n]; ++i) {
    int j = lower_bound(s + i, s + n + 1, s[i] + S) - s; // s[j] >= s[i] + S
    ans = min(ans, j - i);                               // j is not included
  }
  printf("%d\n", ans);
}