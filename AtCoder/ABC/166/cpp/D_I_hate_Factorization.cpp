#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X;

void solve() {
  for (int a = -118; a <= 119; ++a) {
    for (int b = -119; b <= 118; ++b) {
      if ((ll)pow(a, 5) - (ll)pow(b, 5) == X) {
        printf("%d %d\n", a, b);
        return;
      }
    }
  }
}

int main() {
  cin >> X;
  solve();
}