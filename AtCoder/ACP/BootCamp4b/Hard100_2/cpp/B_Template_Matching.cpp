#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 50
using namespace std;

int N, M;
vector<string> A, B;

void solve() {
  for (int i = 0 ; i <= N - M; ++i) {
    for (int j = 0; j <= N - M; ++j) {
      bool f = true;
      for (int _i = 0; _i < M; ++_i) {
        for (int _j = 0; _j < M; ++_j) {
          if (A[i + _i][j + _j] != B[_i][_j]) {
            f = false;
          }
        }
      }
      if (f) {
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

int main() {
  cin >> N >> M;
  A = vector<string>(N), B = vector<string>(M);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  solve();
}