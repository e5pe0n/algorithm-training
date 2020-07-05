#include <iostream>
#include <stdio.h>

#define MAX_N 100
#define MAX_X 100
#define INF 1'000'000'000

using namespace std;

int X[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  int res = INF;
  for (int i = 1; i <= MAX_X; ++i) {
    int t = 0;
    for (int j = 0; j < N; ++j) {
      t += (i - X[j]) * (i - X[j]);
    }
    res = min(res, t);
  }
  printf("%d\n", res);
}