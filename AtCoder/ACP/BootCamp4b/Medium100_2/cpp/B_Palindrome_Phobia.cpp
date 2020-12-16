#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  int a = 0;
  int b = 0;
  int c = 0;
  for (auto s : S) {
    if (s == 'a') {
      ++a;
    } else if (s == 'b') {
      ++b;
    } else {
      ++c;
    }
  }
  if (abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) {
    puts("YES");
  } else {
    puts("NO");
  }
}

int main() {
  cin >> S;
  solve();
}