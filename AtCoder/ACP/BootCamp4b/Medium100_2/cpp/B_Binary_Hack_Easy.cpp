#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  deque<char> q;
  for (auto s : S) {
    if (s == '0' || s == '1') {
      q.push_back(s);
    } else {
      if (!q.empty()) {
        q.pop_back();
      }
    }
  }
  string res;
  while (!q.empty()) {
    res += q.front();
    q.pop_front();
  }
  printf("%s\n", res.c_str());
}

int main() {
  cin >> S;
  solve();
}