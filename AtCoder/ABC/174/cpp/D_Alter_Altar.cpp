#include <bits/stdc++.h>
using namespace std;

int N;
string C;

void solve() {
  int cnt_R = 0;
  int cnt_W = 0;
  for (auto c : C) {
    if (c == 'R') {
      ++cnt_R;
    } else {
      ++cnt_W;
    }
  }
  int res = 0;
  for (int i = 0; i < cnt_R; ++i) {
    if (C[i] == 'W') {
      ++res;
    }
    printf("%d\n", res);
  }

  int main() {
    cin >> N;
    cin >> C;
    solve();
  }