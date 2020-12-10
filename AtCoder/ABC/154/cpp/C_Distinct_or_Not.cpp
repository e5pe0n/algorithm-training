#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N;
int A[MAX_N];

void solve() {
  sort(A, A + N);
  for (int i = 0; i < N - 1; ++i) {
    if (A[i] == A[i + 1]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}