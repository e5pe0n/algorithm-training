#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt = 0;
  int res = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      ++cnt;
    } else {
      res = max(res, cnt);
      cnt = 0;
    }
  }
  res = max(res, cnt);
  printf("%d\n", res);
}