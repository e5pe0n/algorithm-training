#include <iostream>
#include <stdio.h>

#define MAX_N 100
#define MAX_M 100

using namespace std;

int T[MAX_N];
int _T[MAX_M];

int main() {
  int N;
  cin >> N;
  int t = 0;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
    t += T[i];
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int p, x;
    cin >> p >> x;
    _T[i] = t - T[p - 1] + x;
  }
  for (int i = 0; i < M; ++i) {
    printf("%d\n", _T[i]);
  }
}