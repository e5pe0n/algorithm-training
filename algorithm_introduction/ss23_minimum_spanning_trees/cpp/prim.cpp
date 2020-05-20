#include <limits>
#include <queue>
#include <stdio.h>

using namespace std;

const int I_MAX = numeric_limits<int>::max();

int N = 9;
int d[100];
int p[100];
int w[100][100];

struct V {
  int key;
  int p;
};

void mst_prim(int N, bool *s, int *d, int *p, int **w, int r) {
  for (int i = 0; i < N; ++i) {
    d[i] = I_MAX;
    p[i] = -1;
  }
  d[r] = 0;
  priority_queue<int, vector<int>, greater<vector<int>::value_type>> q;
  for (int i = 0; i < N; ++i) {
    q.push(i);
  }
  while (!q.empty()) {
  }
}

int main() {
  w[0][1] = 4;
  w[0][7] = 8;
  w[1][2] = 8;
  w[1][7] = 11;
  w[2][3] = 7;
  w[2][5] = 4;
  w[2][8] = 2;
  w[3][4] = 9;
  w[3][5] = 14;
  w[4][5] = 10;
  w[5][6] = 2;
  w[6][7] = 1;
  w[6][8] = 6;
  w[7][8] = 7;
}
