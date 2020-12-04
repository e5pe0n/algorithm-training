#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N, M;
int A[MAX_N];

void solve() {
  int a = 0;
  for (int i = 0; i < N; ++i) {
    a += A[i];
  }
  int t = 0;
  for (int i = 0; i < N; ++i) {
    if (4 * M * A[i] >= a) {
      ++t;
    }
  }
  if (t >= M) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}