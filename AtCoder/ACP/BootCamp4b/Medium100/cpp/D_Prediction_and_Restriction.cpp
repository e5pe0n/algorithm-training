#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (T[i] == 'r') {
      res += P;
      if (i + K < N && T[i + K] == 'r') {
        T[i + K] = 'x';
      }
    }
    if (T[i] == 's') {
      res += R;
      if (i + K < N && T[i + K] == 's') {
        T[i + K] = 'x';
      }
    }
    if (T[i] == 'p') {
      res += S;
      if (i + K < N && T[i + K] == 'p') {
        T[i + K] = 'x';
      }
    }
  }
  printf("%d\n", res);
}