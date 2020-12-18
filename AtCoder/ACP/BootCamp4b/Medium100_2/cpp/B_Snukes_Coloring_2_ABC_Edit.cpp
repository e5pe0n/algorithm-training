#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int W, H, N;
int X[MAX_N], Y[MAX_N], A[MAX_N];

void solve() {
  int top = H;
  int bottom = 0;
  int left = 0;
  int right = W;
  for (int i = 0; i < N; ++i) {
    if (A[i] == 1) {
      left = max(left, X[i]);
    } else if (A[i] == 2) {
      right = min(right, X[i]);
    } else if (A[i] == 3) {
      bottom = max(bottom, Y[i]);
    } else {
      top = min(top, Y[i]);
    }
  }
  int res = max(0, top - bottom) * max(0, right - left);
  printf("%d\n", res);
}

int main() {
  cin >> W >> H >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> A[i];
  }
  solve();
}