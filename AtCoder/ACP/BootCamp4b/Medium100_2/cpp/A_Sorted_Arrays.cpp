#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  int i = 0;
  int res = 0;
  while (i < N) {
    ++res;
    while (i + 1 < N && A[i + 1] - A[i] == 0) {
      ++i;
    }
    if (i >= N - 1) {
      break;
    }
    ll d = A[i + 1] - A[i];
    while (i + 1 < N && (A[i + 1] - A[i]) * d >= 0) {
      ++i;
    }
    ++i;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}