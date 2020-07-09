#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int B[MAX_N]{};

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;
  for (int i = 0; i < Q; ++i) {
    int b;
    cin >> b;
    ++B[b - 1];
  }
  for (int i = 0; i < N; ++i) {
    if (B[i] + K - Q <= 0) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
}