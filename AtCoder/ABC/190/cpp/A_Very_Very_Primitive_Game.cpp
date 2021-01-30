#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, C;

void solve() {
  if (C == 0) {
    if (A > B)
      puts("Takahashi");
    else
      puts("Aoki");
  } else {
    if (B > A)
      puts("Aoki");
    else
      puts("Takahashi");
  }
}

int main() {
  cin >> A >> B >> C;
  solve();
}