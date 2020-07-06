#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 101

using namespace std;

int A[MAX_N];

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int left = 0;
  int right = 0;
  for (int i = 0; i < M; ++i) {
    int a;
    cin >> a;
    if (a < X) {
      ++left;
    } else {
      ++right;
    }
  }
  printf("%d\n", min(left, right));
}