#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> S;

void solve() {
  int cnt_BA = 0;
  int cnt_B = 0;
  int cnt_A = 0;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i][0] == 'B' && S[i][S[i].size() - 1] == 'A') {
      ++cnt_BA;
    }  else if (S[i][0] == 'B') {
      ++cnt_B;
    } else if (S[i][S[i].size() - 1] == 'A') {
      ++cnt_A;
    }
    for (int j = 0; j < S[i].size() - 1; ++j) {
      if (S[i][j] == 'A' && S[i][j + 1] == 'B') {
        ++res;
      }
    }
  }
  if (cnt_BA > 0) {
    res += cnt_BA - 1;
    if (cnt_A > 0) {
      ++res;
      --cnt_A;
    }
    if (cnt_B > 0) {
      ++res;
      --cnt_B;
    }
  }
  res += min(cnt_A, cnt_B);
  printf("%d\n", res);
}

int main() {
  cin >> N;
  S = vector<string>(N);
  for (int i = 0 ; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}