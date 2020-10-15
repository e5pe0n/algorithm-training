#include <iostream>
#include <stdio.h>
#include <unordered_set>

#define MAX_N 100'000
#define MAX_A 100'000

using namespace std;

int A[MAX_A]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++A[a - 1];
  }
  int cnt = 0;
  int even_cnt = 0;
  for (int i = 0; i < MAX_A; ++i) {
    if (A[i] > 0) {
      ++cnt;
      if (A[i] % 2 == 0) {
        ++even_cnt;
      }
    }
  }
  int ans = cnt - (even_cnt % 2 != 0);
  printf("%d\n", ans);
}