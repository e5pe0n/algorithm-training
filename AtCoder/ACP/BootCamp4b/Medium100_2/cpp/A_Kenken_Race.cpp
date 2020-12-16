#include <bits/stdc++.h>
using namespace std;

int N, A, B, C, D;
string S;

void solve() {
  int cnt = 0;
  for (int i = A; i < C; ++i) {
    if (S[i] == '.') {
      cnt = 0;
    } else {
      ++cnt;
      if (cnt >= 2) {
        puts("No");
        return;
      }
    }
  }
  cnt = 0;
  for (int i = B; i < D; ++i) {
    if (S[i] == '.') {
      cnt = 0;

    } else {
      ++cnt;
      if (cnt >= 2) {
        puts("No");
        return;
      }
    }
  }
  if (C > D) {
    int space = 0;
    for (int i = B - 1; i <= D + 1; ++i) {
      if (S[i] == '.') {
        ++space;
        if (space >= 3) {
          break;
        }
      } else {
        space = 0;
      }
    }
    if (space < 3) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  cin >> N >> A >> B >> C >> D >> S;
  --A;
  --B;
  --C;
  --D;
  solve();
}