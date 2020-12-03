#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;

int N, M;
int H[MAX_N], A[MAX_M], B[MAX_M];
vector<int> G[MAX_N];

void solve() {
  for (int i = 0; i < M; ++i) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  int res = 0;
  for (int u = 0; u < N; ++u) {
    int cnt = 0;
    for (auto v : G[u]) {
      if (H[u] > H[v]) {
        ++cnt;
      }
    }
    if (cnt == G[u].size()) {
      ++res;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}