#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int N;
int A[MAX_N];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int ma = 0;
  for (int i = 0; i < N; ++i) {
    ma = max(ma, A[i]);
  }
  int res = 0;
  int mcnt = 0;
  for (int k = 2; k <= ma; ++k) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (A[i] % k == 0) {
        ++cnt;
      }
    }
    if (mcnt < cnt) {
      mcnt = cnt;
      res = k;
    }
  }
  printf("%d\n", res);
}