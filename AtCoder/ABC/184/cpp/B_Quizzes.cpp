#include <bits/stdc++.h>
using namespace std;

int N, X;
string S;

int main() {
  cin >> N >> X >> S;
  for (auto s : S) {
    if (s == 'o') {
      ++X;
    } else if (X > 0) {
      --X;
    }
  }
  printf("%d\n", X);
}