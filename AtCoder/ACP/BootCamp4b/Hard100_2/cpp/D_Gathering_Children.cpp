#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  int N = S.size();
  vector<int> C(N);
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'R') {
      ++cnt;
    } else {
      C[i] += cnt / 2;
      if (i - 1 >= 0) {
        C[i - 1] += (cnt + 2 - 1) / 2;
      }
      cnt = 0;
    }
  }
  cnt = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == 'L') {
      ++cnt;
    } else {
      C[i] += cnt / 2;
      if (i + 1 <= N - 1) {
        C[i + 1] += (cnt + 2 - 1) / 2;
      }
      cnt = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%d%c", C[i], i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> S;
  solve();
}