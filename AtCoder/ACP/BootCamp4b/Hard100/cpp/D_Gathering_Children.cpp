#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100'000

using namespace std;

int C[MAX_N]{};

int main() {
  string S;
  cin >> S;
  int i = 0;
  int N = S.size();
  while (i < N) {
    int cnt = 0;
    while (i < N && S[i] == 'R') {
      ++i;
      ++cnt;
    }
    C[i - 1] += cnt / 2 + (cnt % 2 != 0);
    C[i] += cnt / 2;
    while (i < N && S[i] == 'L') {
      ++i;
    }
  }
  i = N - 1;
  while (i >= 0) {
    int cnt = 0;
    while (i >= 0 && S[i] == 'L') {
      --i;
      ++cnt;
    }
    C[i + 1] += cnt / 2 + (cnt % 2 != 0);
    C[i] += cnt / 2;
    while (i >= 0 && S[i] == 'R') {
      --i;
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%d\n", C[i]);
  }
}