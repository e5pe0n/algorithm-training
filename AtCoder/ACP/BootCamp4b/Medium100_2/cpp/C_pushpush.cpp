#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N;
int A[MAX_N];

void solve() {
  deque<int> B;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      B.push_back(A[i]);
    } else {
      B.push_front(A[i]);
    }
  }
  if (N % 2 == 0) {
    for (int i = 0; i < N; ++i) {
      printf("%d%c", B[i], i == N - 1 ? '\n' : ' ');
    }
  } else {
    for (int i = N - 1; i >= 0; --i) {
      printf("%d%c", B[i], i == 0 ? '\n' : ' ');
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}