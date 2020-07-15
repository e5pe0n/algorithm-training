#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_A 100'001

using namespace std;

int A[MAX_A]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++A[a];
    if (a - 1 >= 0) {
      ++A[a - 1];
    }
    if (a + 1 < MAX_A) {
      ++A[a + 1];
    }
  }
  int res = 0;
  for (int i = 0; i < MAX_A; ++i) {
    res = max(res, A[i]);
  }
  printf("%d\n", res);
}