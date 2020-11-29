#include <bits/stdc++.h>
using namespace std;

int X, Y;

void solve() {
  for (int i = 0; i <= X; ++i) {
    if (i * 2 + (X - i) * 4 == Y) {
      puts("Yes");
      return;
    }
  }
  puts("No");
}

int main() {
  cin >> X >> Y;
  solve();
}