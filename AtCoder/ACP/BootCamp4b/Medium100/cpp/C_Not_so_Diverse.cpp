#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

#define MAX_N 200'000

using namespace std;

int A[MAX_N]{};

int main() {
  int N, K;
  cin >> N >> K;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++A[a - 1];
    ++res;
  }
  if (N == K) {
    printf("0\n");
    return 0;
  }
  sort(A, A + N);
  for (int i = N - 1; i >= N - K; --i) {
    res -= A[i];
  }
  printf("%d\n", res);
}