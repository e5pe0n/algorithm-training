#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int D[MAX_N]{};

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  for (int i = 1; i < N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      ++D[min(j - i, abs(i - X) + 1 + abs(j - Y))];
    }
  }
  for (int i = 1; i < N; ++i) {
    printf("%d\n", D[i]);
  }
}