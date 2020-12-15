#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N, K;
int A[MAX_N];

void solve() {
  N -= K;
  int res = 1;
  if (N > 0) {
    res += (N + (K - 1) - 1) / (K - 1);
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}