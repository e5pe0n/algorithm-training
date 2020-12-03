#include <bits/stdc++.h>
#define MAX_N 10
#define MAX_Q 50
using namespace std;

int N, M, Q;
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];
int A[MAX_N];

int dfs(int i) {
  int res = 0;
  if (i == N) {
    for (int j = 0; j < Q; ++j) {
      if (A[b[j]] - A[a[j]] == c[j]) {
        res += d[j];
      }
    }
    return res;
  }
  for (int j = A[i - 1]; j <= M; ++j) {
    A[i] = j;
    res = max(res, dfs(i + 1));
  }
  return res;
}

void solve() {
  A[0] = 1;
  printf("%d\n", dfs(1));
}

int main() {
  cin >> N >> M >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i];
    --b[i];
  }
  solve();
}