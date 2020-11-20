#include <iostream>
#include <stdio.h>

#define MAX_N 50

using namespace std;

int R[MAX_N]{};

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    ++R[a - 1];
    ++R[b - 1];
  }
  for (int i = 0; i < N; ++i) {
    printf("%d\n", R[i]);
  }
}