#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_S 100
using namespace std;

int N;
int S[MAX_N];

void solve() {
  int res = 0;
  int min_s = MAX_S;
  for (int i = 0; i < N; ++i) {
    res += S[i];
    if (S[i] % 10 != 0) {
      min_s = min(min_s, S[i]);
    }
  }
  if (res % 10 == 0) {
    res -= min_s;
  }
  if (res % 10 == 0) {
    res = 0;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}