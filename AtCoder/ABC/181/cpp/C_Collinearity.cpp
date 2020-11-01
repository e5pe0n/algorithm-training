#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int N;
int X[MAX_N], Y[MAX_N];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (i == j || j == k || k == i) {
          continue;
        }
        int dx = X[i] - X[j];
        int dy = Y[i] - Y[j];
        int _dx = X[k] - X[i];
        int _dy = Y[k] - Y[i];
        if (dx * _dy == dy * _dx) {
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
}