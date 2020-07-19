#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  int odd_num = 0;
  int four_num = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] % 4 == 0) {
      ++four_num;
    } else if (A[i] % 2 == 1) {
      ++odd_num;
    }
  }
  if (four_num >= odd_num - (four_num + odd_num == N)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}