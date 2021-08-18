#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

void dfs(ll left, ll right, string s) {
  if (left == 0 && right == 0) {
    puts(s.c_str());
    return;
  }
  if (left > 0) dfs(left - 1, right, s + '(');
  if (right > left) dfs(left, right - 1, s + ')');
}

int main() {
  cin >> N;
  if (N % 2 == 0) dfs(N / 2, N / 2, "");
}