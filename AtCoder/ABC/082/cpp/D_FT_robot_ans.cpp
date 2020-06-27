#include <iostream>
#include <stdio.h>

#define N 16'000
#define O 8'000

using namespace std;

bool X[2][N]{};
bool Y[2][N]{};

int main() {
  string s;
  int x, y;
  cin >> s;
  cin >> x >> y;

  int i = 0;
  int M = s.size();
  int d = 0;
  while (i < M && s[i++] == 'F') {
    ++d;
  }
  X[0][d + O] = true;
  d = 0;
  while (i < M && s[i++] == 'F') {
    ++d;
  }
  Y[0][d + O] = true;
  Y[0][-d + O] = true;

  int j = 1;
  while (i < M) {
    d = 0;
    while (i < M && s[i++] == 'F') {
      ++d;
    }
    for (int k = 0; k < N; ++k) {
      if ((k - d) >= 0 && (k + d) < N) {
        X[j % 2][k] = X[(j - 1) % 2][k - d] || X[(j - 1) % 2][k + d];
      } else if ((k - d) >= 0) {
        X[j % 2][k] = X[(j - 1) % 2][k - d];
      } else if ((k + d) < N) {
        X[j % 2][k] = X[(j - 1) % 2][k + d];
      }
    }

    d = 0;
    while (i < M && s[i++] == 'F') {
      ++d;
    }
    for (int k = 0; k < N; ++k) {
      if ((k - d) >= 0 && (k + d) < N) {
        Y[j % 2][k] = Y[(j - 1) % 2][k - d] || Y[(j - 1) % 2][k + d];
      } else if ((k - d) >= 0) {
        Y[j % 2][k] = Y[(j - 1) % 2][k - d];
      } else if ((k + d) < N) {
        Y[j % 2][k] = Y[(j - 1) % 2][k + d];
      }
    }
    ++j;
  }
  bool res = X[(j - 1) % 2][x + O] && Y[(j - 1) % 2][y + O];
  if (res) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}