#include <bits/stdc++.h>
using namespace std;

int N;
string S;
bool used[26];

void solve() {
  int res = 0;
  for (int md = 1; md < N - 1; ++md) {
    memset(used, 0, 26);
    for (int i = 0; i < md; ++i) {
      used[S[i] - 'a'] = true;
    }
    int cnt = 0;
    for (int i = md; i < N; ++i) {
      if (used[S[i] - 'a']) {
        used[S[i] - 'a'] = false;
        ++cnt;
      }
    }
    res = max(res, cnt);
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}