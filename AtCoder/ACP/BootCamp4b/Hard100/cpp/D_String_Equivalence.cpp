#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_N 10

using namespace std;

int N;
vector<string> V;

void dfs(string s, char max_c) {
  if (s.size() == N) {
    V.push_back(s);
    return;
  }
  for (char c = 'a'; c <= max_c + 1; ++c) {
    dfs(s + c, max(max_c, c));
  }
}

int main() {
  cin >> N;
  dfs("a", 'a');
  for (auto v : V) {
    printf("%s\n", v.c_str());
  }
}