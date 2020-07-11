#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100'000

using namespace std;

bool A[MAX_N]{};
int B[MAX_N]{};

int main() {
  int N, M;
  cin >> N >> M;
  int cnt = 0;
  for (int i = 0; i < M; ++i) {
    int p;
    string S;
    cin >> p >> S;
    if (!A[p - 1]) {
      if (S == "AC") {
        ++cnt;
        A[p - 1] = true;
      } else {
        ++B[p - 1];
      }
    }
  }
  int _cnt = 0;
  for (int i = 0; i < N; ++i) {
    _cnt += A[i] * B[i];
  }
  printf("%d %d\n", cnt, _cnt);
}