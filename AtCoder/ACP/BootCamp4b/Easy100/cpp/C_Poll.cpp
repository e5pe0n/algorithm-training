#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> M;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    if (M.count(s)) {
      ++M[s];
    } else {
      M.insert({s, 1});
    }
  }
  int n = 0;
  for (auto &m : M) {
    n = max(n, m.second);
  }
  for (auto &m : M) {
    if (m.second == n) {
      printf("%s\n", m.first.c_str());
    }
  }
}