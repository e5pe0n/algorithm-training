#include <bits/stdc++.h>
#define MAX_M 1'000
using namespace std;

int N, M, T;
int A[MAX_M], B[MAX_M];

void solve() {
  int t = N;
  for (int i = 0; i < M; ++i) {
    if (i == 0) {
      t -= A[i];
    } else {
      t -= A[i] - B[i - 1];
    }
    if (t <= 0) {
      puts("No");
      return;
    }
    t = min(N, t + B[i] - A[i]);
  }
  t -= T - B[M - 1];
  if (t > 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> N >> M >> T;
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}