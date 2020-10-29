#include <fstream>
#include <stdio.h>

#define MAX_N 50000
#define MAX_K 100'000

using namespace std;

int par[MAX_N * 3], rnk[MAX_N * 3]{};
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void init() {
  for (int i = 0; i < N * 3; ++i) {
    par[i] = i;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) {
      ++rnk[x];
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

int main() {
  ifstream ifs("../testset/food_chain/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < K; ++i) {
    int x, y;
    ifs >> T[i] >> x >> y;
    X[i] = x - 1;
    Y[i] = y - 1;
  }
  init();
  int ans = 0;
  for (int i = 0; i < K; ++i) {
    int t = T[i], x = X[i], y = Y[i];
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ++ans;
      continue;
    }
    if (t == 1) {
      if (same(x, y + N) || same(x, y + 2 * N)) {
        ++ans;
      } else {
        unite(x, y);
        unite(x + N, y + N);
        unite(x + N * 2, y + N * 2);
      }
    } else {
      if (same(x, y) || same(x, y + 2 * N)) {
        ++ans;
      } else {
        unite(x, y + N);
        unite(x + N, y + 2 * N);
        unite(x + 2 * N, y);
      }
    }
  }
  printf("%d\n", ans);
}