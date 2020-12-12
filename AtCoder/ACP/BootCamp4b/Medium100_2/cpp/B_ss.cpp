#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  int N = S.size() - 2;
  while (N > 0) {
    bool f = true;
    for (int i = 0; i < N / 2; ++i) {
      if (S[i] != S[i + N / 2]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
    N -= 2;
  }
  printf("%d\n", N);
}

int main() {
  cin >> S;
  solve();
}