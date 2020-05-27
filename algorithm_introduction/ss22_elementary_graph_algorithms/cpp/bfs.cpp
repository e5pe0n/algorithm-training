#include <deque>
#include <limits>
#include <stdio.h>
#include <vector>

using namespace std;

int I_MAX = numeric_limits<int>::max();

int N = 8;
vector<int> V[8];
int d[8]{};
int p[8]{};

void BFS(vector<int> *V, int s) {
  for (int i = 0; i < N; ++i) {
    d[i] = I_MAX;
  }
  deque<int> dq{s};
  d[s] = 0;

  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();
    for (int i = 0; i < V[u].size(); ++i) {
      int v = V[u][i];
      if (d[v] >= I_MAX) {
        d[v] = d[u] + 1;
        p[v] = u;
        dq.push_back(v);
      }
    }
  }
}

void print_path(int *p, int s, int v) {
  if (s == v) {
    printf("%d", s);
  } else if (v < 0) {
    printf("Path from %d to %d does not exist.", s, v);
  } else {
    print_path(p, s, p[v]);
    printf("->%d", v);
  }
}

int main() {
  V[0] = vector<int>{1, 4};
  V[1] = vector<int>{0, 5};
  V[2] = vector<int>{3, 5, 6};
  V[3] = vector<int>{2, 6, 7};
  V[4] = vector<int>{0};
  V[5] = vector<int>{1, 2, 6};
  V[6] = vector<int>{2, 3, 5, 7};
  V[7] = vector<int>{3, 6};

  int s = 1;
  BFS(V, s);

  for (int i = 0; i < N; ++i) {
    printf("d[%d]: %d\n", i, d[i]);
  }

  print_path(p, s, 7);
  printf("\n");
}
