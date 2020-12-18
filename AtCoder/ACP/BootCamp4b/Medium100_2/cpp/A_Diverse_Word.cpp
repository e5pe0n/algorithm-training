#include <bits/stdc++.h>
using namespace std;

string S;
int used[26];

void solve() {
  string res = "";
  int N = S.size();
  if (N < 26) {
    for (auto s : S) {
      used[s - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
      if (!used[i]) {
        res = S + string(1, i + 'a');
        break;
      }
    }
  } else {
    int i = N - 2;
    vector<char> V{S[N - 1]};
    while (i >= 0) {
      for (auto v : V) {
        if (S[i] < v) {
          res = S.substr(0, i) + v;
          printf("%s\n", res.c_str());
          return;
        }
      }
      V.push_back(S[i--]);
      sort(V.begin(), V.end());
    }
    res = "-1";
  }
  printf("%s\n", res.c_str());
}

int main() {
  cin >> S;
  solve();
}