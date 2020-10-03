#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int A[MAX_N]{};

int main() {
  int n;
  cin >> n;
  double max_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    max_a = max(max_a, (double)A[i]);
  }
  double half = max_a / 2.0;
  double min_diff = max_a;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if ((int)max_a != A[i]) {
      double diff = abs(half - A[i]);
      if (diff < min_diff) {
        k = A[i];
        min_diff = diff;
      }
    }
  }
  printf("%d %d\n", (int)max_a, k);
}