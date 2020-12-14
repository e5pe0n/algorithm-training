#include <bits/stdc++.h>
using namespace std;

const string T = "keyence";

string S;

void solve() {
  int NS = S.size();
  int NT = T.size();
  for (int i = 0; i <= NT; ++i) {
    if (S.substr(0, i) == T.substr(0, i) && S.substr(NS - NT + i) == T.substr(i)) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main() {
  cin >> S;
  solve();
}