#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int C[26]{};

int main() {
  string s;
  cin >> s;
  int N = s.size();
  int t = N;
  for (int i = 0; i < 26; ++i) {
    int j = 0;
    int _t = 0;
    while (j < N) {
      int cnt = 0;
      while (j < N && s[j] == i + 'a') {
        ++j;
      }
      while (j < N && s[j] != i + 'a') {
        ++cnt;
        ++j;
      }
      _t = max(_t, cnt);
    }
    t = min(t, _t);
  }
  printf("%d\n", t);
}