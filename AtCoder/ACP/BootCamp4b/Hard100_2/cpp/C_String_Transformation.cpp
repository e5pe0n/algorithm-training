#include <bits/stdc++.h>
using namespace std;

string S, T;
char CS[26];
char CT[26];

void solve() {
  bool f = true;
  for (int i = 0; i < S.size(); ++i) {
    if (CS[S[i] - 'a'] && CS[S[i] - 'a'] != T[i]) {
      f = false;
      break;
    } else {
      CS[S[i] - 'a'] = T[i];
    }
    if (CT[T[i] - 'a'] && CT[T[i] - 'a'] != S[i]) {
      f = false;
      break;
    } else {
      CT[T[i] - 'a'] = S[i];
    }
  }
  if (f) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> S >> T;
  solve();
}