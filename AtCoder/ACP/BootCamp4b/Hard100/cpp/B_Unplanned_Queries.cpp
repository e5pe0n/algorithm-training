#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100'000

using namespace std;

int N, M;
int C[MAX_N]{};

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    ++C[a - 1];
    ++C[b - 1];
  }
  string ans = "YES";
  for (int i = 0; i < N; ++i) {
    if (C[i] % 2 != 0) {
      ans = "NO";
      break;
    }
  }
  printf("%s\n", ans.c_str());
}