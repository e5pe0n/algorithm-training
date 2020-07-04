// without replacement
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int n = 3;
  int k = 2;
  vector<bool> v(n);
  fill(v.end() - k, v.end(), true);
  do {
    for (int i = 0; i < n; ++i) {
      if (v[i]) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  } while (next_permutation(v.begin(), v.end()));

  // 2 3
  // 1 3
  // 1 2
}
