#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N, K;
int P[MAX_N];
double E[MAX_N];
double sum[MAX_N + 1];

void solve() {
  for (int i = 0; i < N; ++i) {
    E[i] = (P[i] + 1.0) / 2;
    sum[i + 1] = sum[i] + E[i];
  }
  double res = 0;
  for (int i = 0; i + K <= N; ++i) {
    res = max(res, sum[i + K] - sum[i]);
  }
  printf("%.7f\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  solve();
}