#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll K;
string res;

string dfs(string s) {
  if (K <= 0) return "";
  if (S.find(s) == string::npos)
    return "";
  else {
    if (--K == 0) return s;
  }
  string res = "";
  for (char c = 'a'; c <= 'z'; ++c) {
    res += dfs(s + c);
  }
  return res;
}

void solve() {
  for (char c = 'a'; c <= 'z'; ++c) {
    string res = dfs(string(1, c));
    if (res.size()) {
      puts(res.c_str());
      return;
    }
  }
}

int main() {
  cin >> S >> K;
  solve();
}