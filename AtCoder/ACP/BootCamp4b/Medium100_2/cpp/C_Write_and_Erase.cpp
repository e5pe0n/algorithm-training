#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
map<int, int> cnt;

void solve() {
  int res = 0;
  for (auto p : cnt) {
    if (p.second % 2 != 0) {
      ++res;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++cnt[a];
  }
  solve();
}