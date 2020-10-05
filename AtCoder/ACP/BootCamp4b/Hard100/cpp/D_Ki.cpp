#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 200'001

using namespace std;

typedef long long ll;

ll C[MAX_N]{};

void dfs(int u, int p, vector<vector<int>> &V) {
  C[u] += C[p];
  for (auto v : V[u]) {
    if (v != p) {
      dfs(v, u, V);
    }
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> V(N + 1, vector<int>{});
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  for (int i = 0; i < Q; ++i) {
    int p, x;
    cin >> p >> x;
    C[p] += x;
  }
  int u = 1;
  int p = 0;
  dfs(u, p, V);
  for (int i = 1; i <= N; ++i) {
    printf("%lld\n", C[i]);
  }
}