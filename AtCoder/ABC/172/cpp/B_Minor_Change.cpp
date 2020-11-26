#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
  cin >> S >> T;
  int cnt = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] != T[i]) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
}