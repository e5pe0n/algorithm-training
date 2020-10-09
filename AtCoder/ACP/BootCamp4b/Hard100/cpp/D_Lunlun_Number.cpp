#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
string ans = "";

void dfs(string n_str, int d, int digit, int K) {
  if (d >= digit) {
    if (++cnt == K) {
      ans = n_str;
    }
    return;
  }
  int last = n_str[n_str.size() - 1] - '0';
  for (int i = max(0, last - 1); i <= min(9, last + 1); ++i) {
    dfs(n_str + to_string(i), d + 1, digit, K);
  }
}

int main() {
  int K;
  cin >> K;
  int digit = 1;
  while (ans == "") {
    for (int i = 1; i <= 9; ++i) {
      dfs(to_string(i), 1, digit, K);
    }
    ++digit;
  }
  printf("%s\n", ans.c_str());
}