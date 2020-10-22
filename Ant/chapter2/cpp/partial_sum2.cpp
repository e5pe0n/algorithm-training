#include <bitset>
#include <fstream>
#include <iostream>
#include <stdio.h>

#define MAX_N 20

using namespace std;

int N, K;
int A[MAX_N]{};

int main() {
  ifstream ifs("../testset/partial_sum/test2.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  ifs >> K;
  bool possible = false;
  for (int i = 1; i < (1 << N); ++i) {
    bitset<MAX_N> B(i);
    int t = 0;
    for (int j = 0; j < N; ++j) {
      if (B.test(j)) {
        t += A[j];
      }
    }
    if (t == K) {
      possible = true;
      break;
    }
  }
  if (possible) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
