#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string A = "atcoder";
const string win = "You can win";
const string lose = "You will lose";
string S, T;

int main() {
  cin >> S >> T;
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] != T[i]) {
      if (T[i] == '@') swap(S[i], T[i]);
      if (S[i] != '@') {
        puts(lose.c_str());
        return 0;
      }
      bool f = false;
      for (auto a : A) {
        if (a == T[i]) f = true;
      }
      if (!f) {
        puts(lose.c_str());
        return 0;
      }
    }
  }
  puts(win.c_str());
}