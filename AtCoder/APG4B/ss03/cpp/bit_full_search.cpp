#include <bitset>
#include <iostream>
#include <stdio.h>

#define MAX_N 20

using namespace std;

int A[MAX_N];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (int i = 0; i < (1 << N); ++i) {
    bitset<20> b(i);
    int s = 0;
    for (int j = 0; j < N; ++j) {
      if (b.test(j)) {
        s += A[j];
      }
    }
    if (s == K) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}