#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  int N = S.size();
  int res = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i + 1] != S[i]) {
      ++res;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> S;
  solve();
}