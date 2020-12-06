#include <bits/stdc++.h>
#define MAX_M 5
#define MAX_N 3
using namespace std;

int N, M;
int n[MAX_N], cnt[MAX_N];
int s[MAX_M], c[MAX_M];

void solve() {
  int res = 0;
  for (int i = 0; i < M; ++i) {
    if (N >= 2 && s[i] == 0 && c[i] == 0) {
      res = -1;
      break;
    }
    if (cnt[s[i]] > 0 && n[s[i]] != c[i]) {
      res = -1;
      break;
    }
    n[s[i]] = c[i];
    ++cnt[s[i]];
  }
  if (res >= 0) {
    if (N >= 2) {
      n[0] = max(1, n[0]);
    }
    for (int i = 0; i < N; ++i) {
      res += n[i] * (int)pow(10, N - i - 1);
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> s[i] >> c[i];
    --s[i];
  }
  solve();
}