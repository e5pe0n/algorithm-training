#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_K 100
using namespace std;

int N, K;
int A[MAX_N][MAX_K];

int main() {
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    int d;
    cin >> d;
    for (int j = 0; j < d; ++j) {
      int a;
      cin >> a;
      A[a - 1][i] += 1;
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    bool f = false;
    for (int j = 0; j < K; ++j) {
      if (A[i][j] > 0) {
        f = true;
        break;
      }
    }
    if (!f) {
      ++res;
    }
  }
  printf("%d\n", res);
}