#include <bits/stdc++.h>
using namespace std;

int A, B, C;

void solve() {
  int g = __gcd(A, B);
  if (C % g == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
}

int main() {
  cin >> A >> B >> C;
  solve();
}