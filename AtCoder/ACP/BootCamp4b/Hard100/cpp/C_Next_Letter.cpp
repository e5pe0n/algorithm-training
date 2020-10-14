#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  int K;
  cin >> s >> K;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int d = ('z' - s[i] + 1) % 26;
    if (K >= d) {
      K -= d;
      s[i] = 'a';
    }
  }
  s[n - 1] = 'a' + (s[n - 1] - 'a' + K) % 26;
  printf("%s\n", s.c_str());
}