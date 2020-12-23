#include <bits/stdc++.h>
using namespace std;

string _S, T;

void solve() {
  string res;
  reverse(_S.begin(), _S.end());
  reverse(T.begin(), T.end());
  int N = _S.size();
  int M = T.size();
  for (int i = 0; i + M <= N; ++i) {
    bool f = true;
    for (int j = 0; j < M; ++j) {
      if (_S[i + j] != T[j] && _S[i + j] != '?') {
        f = false;
      }
    }
    if (f) {
      res += T + _S.substr(i + M);
      for (int j = 0; j < res.size(); ++j) {
        if (res[j] == '?') {
          res[j] = 'a';
        }
      }
      reverse(res.begin(), res.end());
      printf("%s\n", res.c_str());
      return;
    }
    res += _S[i];
  }
  puts("UNRESTORABLE");
}

int main() {
  cin >> _S >> T;
  solve();
}