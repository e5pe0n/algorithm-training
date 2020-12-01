#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 200'000
using namespace std;

int N, M;
int A[MAX_M], B[MAX_M];
vector<int> G[MAX_N];
int path[MAX_N];

void bfs() {
  memset(path, -1, sizeof(path));
  path[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (path[v] < 0) {
        q.push(v);
        path[v] = u;
      }
    }
  }
}

void solve() {
  for (int i = 0; i < M; ++i) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  bfs();
  for (int i = 1; i < N; ++i) {
    if (path[i] < 0) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
  for (int i = 1; i < N; ++i) {
    printf("%d\n", path[i] + 1);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}