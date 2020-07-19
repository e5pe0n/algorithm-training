#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  string res = "";
  int i = s.size() - 1;
  while (i >= 0) {
    while (i >= 0 && s[i] != 'B') {
      res += s[i--];
    }
    int cnt = 0;
    while (i >= 0 && s[i] == 'B') {
      --i;
      ++cnt;
    }
    i -= cnt;
  }
  for (int i = res.size() - 1; i >= 0; --i) {
    printf("%c", res[i]);
  }
  printf("\n");
}