#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 2000

typedef long long ll;

using namespace std;

int L[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  sort(L, L + N);
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int left = j + 1;
      int right = lower_bound(L, L + N, L[i] + L[j]) - L;
      res += right - left;
    }
  }
  printf("%lld\n", res);
}