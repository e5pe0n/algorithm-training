#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 50

using namespace std;

int V[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> V[i];
  }
  sort(V, V + N);
  double res = 0.5 * (V[0] + V[1]);
  for (int i = 2; i < N; ++i) {
    res = 0.5 * (res + V[i]);
  }
  printf("%f\n", res);
}