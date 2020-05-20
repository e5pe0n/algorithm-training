#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int N = 9;
int p[9];
int rnk[9];

void init(int n) {
  for (int i = 0; i < N; ++i) {
    p[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (p[x] == x) {
    return x;
  } else {
    p[x] = find(p[x]);
    return p[x];
  }
}

void uni(int x, int y) {
  int x = find(x);
  int y = find(y);
  if (x == y) {
    return;
  }

  if (rnk[x] > rnk[y]) {
    p[y] = x;
  } else {
    p[x] = y;
    if (rnk[x] == rnk[y]) {
      ++rnk[y];
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

struct Edge {
  int u;
  int v;
  int weight;
  string to_str() {
    return "(u: " + to_string(u) + ", v: " + to_string(v) + ", weight: " + to_string(weight) + ")";
  }
};

vector<Edge> mst_kruscal(vector<Edge> E, int N) {
  vector<Edge> A;

  init(N);

  auto comp = [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; };
  sort(E.begin(), E.end(), comp);

  for (auto e : E) {
    if (!same(e.u, e.v)) {
      A.push_back(e);
      uni(e.u, e.v);
    }
  }
  return A;
}

int main() {
  vector<Edge> E{Edge{0, 1, 4}, Edge{0, 7, 8}, Edge{1, 2, 8},  Edge{1, 7, 11}, Edge{2, 3, 7},
                 Edge{2, 5, 4}, Edge{3, 4, 9}, Edge{3, 5, 14}, Edge{4, 5, 10}, Edge{5, 6, 2},
                 Edge{6, 7, 1}, Edge{6, 8, 6}, Edge{7, 8, 7}};

  vector<Edge> A = mst_kruscal(E, N);
  int total = 0;
  for (auto a : A) {
    total += a.weight;
    printf(a.to_str().c_str());
  }
  printf("total weight: %d\n", total);
}