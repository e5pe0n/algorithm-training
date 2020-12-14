#include <bits/stdc++.h>
using namespace std;

int N;
string s, t;

void solve() {
  int res = N;
  for (int i = 0; i < N; ++i) {
    bool f = true;
    for (int j = i; j < N; ++j) {
      if (s[j] != t[j - i]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
    ++res;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> s >> t;
  solve();
}