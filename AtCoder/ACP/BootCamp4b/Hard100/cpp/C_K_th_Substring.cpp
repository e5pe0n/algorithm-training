#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s;
int K;
int cc;
string ans = "";

void dfs(string _s) {
  if (ans.size() > 0) {
    return;
  }
  if (_s.size() > 0) {
    if (s.find(_s) == string::npos) {
      return;
    } else {
      ++cc;
      if (cc == K) {
        ans = _s;
        return;
      }
    }
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    dfs(_s + c);
  }
}

int main() {
  cin >> s >> K;
  dfs("");
  printf("%s\n", ans.c_str());
}