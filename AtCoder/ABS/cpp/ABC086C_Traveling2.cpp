#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'001

using namespace std;

int X[MAX_N];
int Y[MAX_N];
int T[MAX_N];

int main() {
  int N;
  cin >> N;
  X[0] = 0;
  Y[0] = 0;
  T[0] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> X[i] >> Y[i];
  }

  for (int i = 0; i < N; ++i) {
    int dx = abs(X[i + 1] - X[i]);
    int dy = abs(Y[i + 1] - Y[i]);
    int dt = T[i + 1] - T[i];
    if (!((dt >= dx + dy) && (dt - (dx + dy)) % 2 == 0)) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}