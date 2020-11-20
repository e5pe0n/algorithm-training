#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  string A;
  string B;

  cin >> A >> B;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end(), greater<char>());

  int N = A.size();
  int M = B.size();

  if (N < M) {
    int i = 0;
    while (i < N && A[i] == B[i]) {
      ++i;
    }
    if (i == N) {
      printf("Yes\n");
      return 0;
    }
  }
  int i = 0;
  N = min(N, M);
  while (i < N && A[i] == B[i]) {
    ++i;
  }
  if (i < N && A[i] < B[i]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}