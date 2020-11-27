#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N;
int A[MAX_N];
int a[MAX_N];
int res[MAX_N];

void solve() {
  int x = 1;
  for (int j = 0; j <= 30; ++j) {
    int cnt = 0;
    int cnt_zero = 0;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < N; ++i) {
      int t = A[i] >> j;
      if (t & 1) {
        a[i] = 1;
        ++cnt;
      }
      if (t == 0) {
        ++cnt_zero;
      }
    }
    if (cnt_zero == N) {
      break;
    }
    for (int i = 0; i < N; ++i) {
      if (cnt % 2 == 0) {
        res[i] += a[i] * x;
      } else {
        res[i] += (a[i] ^ 1) * x;
      }
    }
    x *= 2;
  }
  for (int i = 0; i < N; ++i) {
    printf("%d%c", res[i], i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}