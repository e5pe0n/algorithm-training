#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

void solve() {
  ll left = 0;
  ll right = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '(') {
      ++left;
    } else {
      if (left > 0) {
        --left;
      } else {
        ++right;
      }
    }
  }
  string res;
  for (int i = 0; i < right; ++i) {
    res += '(';
  }
  res += S;
  for (int i = 0; i < left; ++i) {
    res += ')';
  }
  printf("%s\n", res.c_str());
}

int main() {
  cin >> N >> S;
  solve();
}