#include <bits/stdc++.h>
using namespace std;

string s, t;

void solve() {
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  if (s < t) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> s >> t;
  solve();
}