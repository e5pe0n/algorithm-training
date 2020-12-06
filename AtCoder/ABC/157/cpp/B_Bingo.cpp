#include <bits/stdc++.h>
#define MAX_N 10
using namespace std;

int A[3][3], B[MAX_N], cnt[8];
int N;

void solve() {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (A[i][j] == B[k]) {
          ++cnt[i];
          ++cnt[j + 3];
          if (i + j == 2) {
            ++cnt[6];
          }
          if (i == j) {
            ++cnt[7];
          }
        }
      }
    }
  }
  int res = false;
  for (int i = 0; i < 8; ++i) {
    if (cnt[i] >= 3) {
      res = true;
      break;
    }
  }
  if (res) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> A[i][j];
    }
  }
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  solve();
}