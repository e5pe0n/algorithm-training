#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200
#define INF 1'000'000'001

using namespace std;

int main() {
  int N;
  cin >> N;
  int n = INF;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a % 2 != 0) {
      printf("0\n");
      return 0;
    }
    int cnt = 1;
    while ((a = a >> 1) % 2 == 0) {
      ++cnt;
    }
    n = min(n, cnt);
  }
  printf("%d\n", n);
}