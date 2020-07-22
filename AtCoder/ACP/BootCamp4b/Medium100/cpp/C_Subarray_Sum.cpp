#include <iostream>
#include <stdio.h>

#define MAX_S 1'000'000'000

using namespace std;

int main() {
  int N, K, S;
  cin >> N >> K >> S;
  for (int i = 0; i < K; ++i) {
    printf("%d ", S);
  }
  if (S == MAX_S) {
    for (int i = K; i < N; ++i) {
      printf("1 ");
    }
  } else {
    for (int i = K; i < N; ++i) {
      printf("%d ", MAX_S);
    }
  }
  printf("\n");
}