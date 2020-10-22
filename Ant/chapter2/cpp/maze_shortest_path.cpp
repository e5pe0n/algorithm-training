#include <deque>
#include <fstream>
#include <stdio.h>
#include <string>
#include <utility>

#define MAX_N 100
#define MAX_M 100
#define INF 1'000'000'000

using namespace std;

typedef pair<int, int> P;

int N, M, si, sj, gi, gj;
string A[MAX_N]{};
int d[MAX_N][MAX_M]{};

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int main() {
  ifstream ifs("../testset/maze_shortest_path/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
    for (int j = 0; j < M; ++j) {
      if (A[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (A[i][j] == 'G') {
        gi = i;
        gj = j;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      d[i][j] = INF;
    }
  }
  d[si][sj] = 0;
  deque<P> q{P(si, sj)};
  while (!q.empty()) {
    P p = q.front();
    q.pop_front();
    int _i = p.first;
    int _j = p.second;
    if (_i == gi && _j == gj) {
      break;
    }
    for (int k = 0; k < 4; ++k) {
      int i = _i + di[k];
      int j = _j + dj[k];
      if (0 <= i && i < N && 0 <= j && j < M && A[i][j] != '#' && d[i][j] == INF) {
        d[i][j] = d[_i][_j] + 1;
        q.push_back(P(i, j));
      }
    }
  }
  printf("%d\n", d[gi][gj]);
}
