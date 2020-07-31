#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if ((M - j) * i + (N - i) * j == K) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
}