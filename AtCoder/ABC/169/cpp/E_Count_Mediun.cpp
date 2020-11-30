#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N;
int A[MAX_N], B[MAX_N];

void solve() {
  sort(A, A + N);
  sort(B, B + N);
  int res = 0;
  int md_A, md_B;
  if (N % 2 == 0) {
    md_A = A[N / 2 - 1] + A[N / 2];
    md_B = B[N / 2 - 1] + B[N / 2];
  } else {
    md_A = A[N / 2];
    md_B = B[N / 2];
  }
  printf("%d\n", md_B - md_A + 1);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}