#include <iostream>
#include <stdio.h>

#define MAX_R 100'001
#define MAX_Q 100'000

using namespace std;

bool B[MAX_R]{};
int C[MAX_R]{};
int A[MAX_Q]{};

void sieve() {
  for (int i = 0; i < MAX_R; ++i) {
    B[i] = true;
  }
  B[0] = B[1] = false;
  for (int i = 2; i < MAX_R; ++i) {
    if (B[i]) {
      for (int j = i * 2; j < MAX_R; j += i) {
        B[j] = false;
      }
    }
  }
}

int main() {
  sieve();
  for (int i = 1; i < MAX_R; ++i) {
    C[i] += C[i - 1] + (i % 2 != 0 && B[i] && B[(i + 1) / 2]);
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r;
    A[i] = C[r] - C[l - 1];
  }
  for (int i = 0; i < Q; ++i) {
    printf("%d\n", A[i]);
  }
}