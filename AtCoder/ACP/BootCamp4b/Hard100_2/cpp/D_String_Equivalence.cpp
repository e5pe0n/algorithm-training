#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void dfs(string s, char max_c) {
  if (s.size() == N) {
    puts(s.c_str());
    return;
  }
  for (char c = 'a'; c <= max_c + 1; ++c) {
    dfs(s + string(1, c), max(c, max_c));
  }
}

void solve() {
  dfs("a", 'a');
}

int main() {
  cin >> N;
  solve();
}