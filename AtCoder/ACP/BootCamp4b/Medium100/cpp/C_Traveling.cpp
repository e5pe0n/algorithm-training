#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'001

using namespace std;

int T[MAX_N];
int X[MAX_N];
int Y[MAX_N];

int main() {
  int N;
  cin >> N;
  T[0] = 0;
  X[0] = 0;
  Y[0] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; ++i) {
    int t = T[i + 1] - T[i];
    int d = abs(X[i + 1] - X[i]) + abs(Y[i + 1] - Y[i]);
    if (!(d <= t && t % 2 == d % 2)) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}