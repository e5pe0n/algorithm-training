#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string C;

void solve() {
  char C1 = C[0];
  bool f = true;
  for (auto c : C) {
    if (c != C1) f = false;
  }
  if (f)
    puts("Won");
  else
    puts("Lost");
}

int main() {
  cin >> C;
  solve();
}