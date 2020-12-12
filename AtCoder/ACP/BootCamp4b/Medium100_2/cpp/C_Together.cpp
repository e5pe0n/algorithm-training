#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
int A[MAX_N];

void solve() {
  map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
    ++cnt[A[i] - 1];
    ++cnt[A[i] + 1];
  }
  int res = 0;
  for (auto p : cnt) {
    res = max(res, p.second);
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