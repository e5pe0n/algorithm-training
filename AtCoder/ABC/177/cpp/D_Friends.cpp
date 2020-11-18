#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int N, M;
int par[MAX_N], rnk[MAX_N];

void init() {
  for (int i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (x == par[x]) {
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
  if (rnk[y] > rnk[x]) {
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
  cin >> N >> M;
  init();
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (!same(a, b)) {
      unite(a, b);
    }
  }
  for (int i = 0; i < N; ++i) {
    find(i);
  }
  map<int, int> m;
  for (int i = 0; i < N; ++i) {
    ++m[par[i]];
  }
  int res = 0;
  for (auto _m : m) {
    res = max(res, _m.second);
  }
  printf("%d\n", res);
}