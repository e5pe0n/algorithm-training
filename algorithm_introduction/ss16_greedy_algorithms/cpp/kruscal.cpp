#include <stdio.h>
#include <vector>

using namespace std;

int par[100]{};
int rnk[100]{};

void init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;

  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
}

bool same(int x, int y) { return find(x) == find(y); }

struct Edge {
  int from;
  int to;
  int weight;
  Edge(char from, char to, int weight) : from(from), to(to), weight(weight) {}
};

vector<Edge> kruscal(vector<Edge> &es) {
  vector<Edge> res;
  auto comp = [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; };
  sort(es.begin(), es.end(), comp);

  init(es.size());
  for (auto e : es) {
    if (!same(e.from, e.to)) {
      unite(e.from, e.to);
      res.push_back(e);
    }
  }
  return res;
}

int main() {
  vector<Edge> es;
  es.emplace_back(0, 1, 6);
  es.emplace_back(0, 2, 15);
  es.emplace_back(1, 3, 10);
  es.emplace_back(3, 2, 1);
  es.emplace_back(3, 4, 5);
  es.emplace_back(2, 4, 4);
  es.emplace_back(3, 5, 9);
  es.emplace_back(4, 7, 3);
  es.emplace_back(5, 6, 14);
  es.emplace_back(5, 7, 8);
  es.emplace_back(6, 7, 12);
  es.emplace_back(4, 8, 7);
  es.emplace_back(6, 8, 13);

  vector<Edge> res = kruscal(es);

  printf("edges: ");
  int total = 0;
  for (auto e : res) {
    total += e.weight;
    printf("(%d, %d, %d), ", e.from, e.to, e.weight);
  }
  printf("\n");
  printf("total weight: %d\n", total);
}

// edges: (3, 2, 1), (4, 7, 3), (2, 4, 4), (0, 1, 6), (4, 8, 7), (5, 7, 8), (1, 3, 10), (6, 7, 12),
// total weight: 51