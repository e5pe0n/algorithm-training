#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 50

using namespace std;

int C[MAX_N][26];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      ++C[i][s[j] - 'a'];
    }
  }
  string res = "";
  for (int i = 0; i < 26; ++i) {
    int t = MAX_N + 1;
    for (int j = 0; j < n; ++j) {
      t = min(t, C[j][i]);
    }
    for (int j = 0; j < t; ++j) {
      res += i + 'a';
    }
  }
  printf("%s\n", res.c_str());
}