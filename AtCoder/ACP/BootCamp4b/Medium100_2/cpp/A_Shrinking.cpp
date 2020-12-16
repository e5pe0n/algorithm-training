#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  int res = S.size();
  for (int i = 0; i < S.size(); ++i) {
    char c = S[i];
    string prv = S;
    string nxt;
    int turn = 0;
    while (true) {
      bool f = true;
      for (int i = 0; i < prv.size(); ++i) {
        if (prv[i] != c) {
          f = false;
          break;
        }
      }
      if (f) {
        res = min(res, turn);
        break;
      }
      for (int i = 0; i < prv.size() - 1; ++i) {
        if (prv[i] == c || prv[i + 1] == c) {
          nxt.push_back(c);
        } else {
          nxt.push_back(prv[i]);
        }
      }
      swap(prv, nxt);
      nxt = "";
      ++turn;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> S;
  solve();
}