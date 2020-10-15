#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_K 9
#define INF 1'000'000'000

using namespace std;

int D[MAX_K + 1]{};

int dfs(int n, int N, const vector<int> &V) {
  if (n >= N) {
    return n;
  }
  int ret = INF;
  for (auto v : V) {
    ret = min(ret, dfs(n * 10 + v, N, V));
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> D[i];
  }
  int idx = 0;
  vector<int> V{};
  for (int i = 0; i < 10; ++i) {
    if (i == D[idx]) {
      ++idx;
    } else {
      V.push_back(i);
    }
  }
  int ans = INF;
  for (auto v : V) {
    if (v != 0) {
      ans = min(ans, dfs(v, N, V));
    }
  }
  printf("%d\n", ans);
}