#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  int left = 0;
  int right = N - 1;
  int cnt = 0;
  bool possible = true;
  while (left <= right) {
    if (s[left] == s[right]) {
      ++left;
      --right;
    } else if (s[left] == 'x' && s[right] != 'x') {
      ++left;
      ++cnt;
    } else if (s[left] != 'x' && s[right] == 'x') {
      --right;
      ++cnt;
    } else {
      possible = false;
      break;
    }
  }
  if (possible) {
    printf("%d\n", cnt);
  } else {
    printf("-1\n");
  }
}