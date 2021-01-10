#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y;

void solve() {
  if (min(X, Y) + 3 > max(X, Y))
    puts("Yes");
  else
    puts("No");
}

int main() {
  cin >> X >> Y;
  solve();
}