#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
int A[MAX_N];

void solve() {
  int four = 0;
  int odd = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] % 4 == 0) {
      ++four;
    } else if (A[i] % 2 != 0) {
      ++odd;
    }
  }
  if (four >= odd - (four + odd == N)) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}