#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string S, T;

int main() {
  cin >> S >> T;
  int res = T.size();
  for (int i = 0; i <= S.size() - T.size(); ++i) {
    int cnt = 0;
    for (int j = 0; j < T.size(); ++j) {
      if (S[i + j] == T[j]) {
        ++cnt;
      }
    }
    res = min(res, (int)T.size() - cnt);
  }
  printf("%d\n", res);
}