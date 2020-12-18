#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
int A[MAX_N];

void solve() {
  map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  int res = 0;
  for (auto p : cnt) {
    if (p.first < p.second) {
      res += p.second - p.first;
    } else if (p.first > p.second) {
      res += p.second;
    }
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