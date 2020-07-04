#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_A 1'000'000'001

using namespace std;

int main() {
  int N;
  cin >> N;
  int res = MAX_A;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    int cnt = 0;
    while (a % 2 == 0) {
      a >>= 1;
      ++cnt;
    }
    res = min(res, cnt);
  }
  printf("%d\n", res);
}