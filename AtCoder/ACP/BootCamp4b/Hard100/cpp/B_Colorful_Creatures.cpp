#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

ll A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  int cnt = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (A[i] * 2 >= A[i + 1]) {
      ++cnt;
    } else {
      cnt = 0;
    }
    A[i + 1] += A[i];
  }
  printf("%d\n", ++cnt);
}