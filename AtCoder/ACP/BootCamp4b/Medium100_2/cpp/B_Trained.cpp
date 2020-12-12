#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;
int a[MAX_N];
bool used[MAX_N];

void solve() {
  int i = 0;
  int res = 0;
  while (!used[i] && i != 1) {
    used[i] = true;
    i = a[i];
    ++res;
  }
  if (i != 1) {
    res = -1;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    --a[i];
  }
  solve();
}