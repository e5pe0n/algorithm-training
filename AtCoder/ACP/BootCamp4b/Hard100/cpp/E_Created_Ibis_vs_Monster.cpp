#include <iostream>
#include <stdio.h>

#define MAX_H 10'000
#define INF 1'000'000'000

using namespace std;

int d[MAX_H + 1]{};

int main() {
  for (int i = 0; i < MAX_H + 1; ++i) {
    d[i] = INF;
  }
  d[0] = 0;
  int H, N;
  cin >> H >> N;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j <= H; ++j) {
      d[min(H, j + a)] = min(d[min(H, j + a)], d[j] + b);
    }
  }
  printf("%d\n", d[H]);
}