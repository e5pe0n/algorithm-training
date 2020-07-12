#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt = 0;
  int _cnt = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '0') {
      ++cnt;
    } else {
      ++_cnt;
    }
  }
  printf("%d\n", min(cnt, _cnt) * 2);
}