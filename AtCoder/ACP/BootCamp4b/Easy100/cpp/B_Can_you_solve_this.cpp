#include <iostream>
#include <stdio.h>

#define MAX_M 10
#define MAX_N 10

using namespace std;

int B[MAX_M];

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  int cnt;
  for (int i = 0; i < N; ++i) {
    int t = 0;
    for (int j = 0; j < M; ++j) {
      int a;
      cin >> a;
      t += B[j] * a;
    }
    cnt += t + C > 0;
  }
  printf("%d\n", cnt);
}