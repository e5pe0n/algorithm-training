#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int left = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') {
      left = i;
      break;
    }
  }
  int right = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'Z') {
      right = i;
      break;
    }
  }
  printf("%d\n", right - left + 1);
}