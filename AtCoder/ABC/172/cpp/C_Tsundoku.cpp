#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
#define MAX_K 1'000'000'000
using namespace std;
typedef long long ll;

int N, M, K;
ll A[MAX_N], B[MAX_M];
ll sum_A[MAX_N + 1], sum_B[MAX_M + 2];

void solve() {
  for (int i = 0; i < N; ++i) {
    sum_A[i + 1] = sum_A[i] + A[i];
  }
  for (int i = 0; i < M; ++i) {
    sum_B[i + 1] = sum_B[i] + B[i];
  }
  sum_B[M + 1] = MAX_K + 1;
  int res = 0;
  for (int i = 0; i <= N; ++i) {
    if (K - sum_A[i] >= 0) {
      int j = upper_bound(sum_B, sum_B + M + 1, K - sum_A[i]) - sum_B;
      res = max(res, i + j - 1);
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  solve();
}