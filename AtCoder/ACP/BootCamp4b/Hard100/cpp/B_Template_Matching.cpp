#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 50
#define MAX_M 50

using namespace std;

string A[MAX_N]{};
string B[MAX_M]{};

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  for (int i = 0; i <= N - M; ++i) {
    for (int j = 0; j <= N - M; ++j) {
      bool found = true;
      for (int _i = 0; _i < M; ++_i) {
        for (int _j = 0; _j < M; ++_j) {
          if (A[i + _i][j + _j] != B[_i][_j]) {
            found = false;
            break;
          }
        }
        if (!found) {
          break;
        }
      }
      if (found) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
}