#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
int P[MAX_N];

void solve() {
  int res = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (i == P[i]) {
      swap(P[i], P[i + 1]);
      ++res;
    }
  }
  if (P[N - 1] == N - 1) {
    swap(P[N - 1], P[N - 2]);
    ++res;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }
  solve();
}