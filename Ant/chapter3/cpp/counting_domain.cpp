#include <algorithm>
#include <fstream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 500

using namespace std;

typedef pair<int, int> pii;

int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
bool field[MAX_N * 6][MAX_N * 6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int compress(int *x1, int *x2, int w) {
  vector<int> xs;
  for (int i = 0; i < N; ++i) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d;
      int tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 < w) {
        xs.push_back(tx1);
      }
      if (0 <= tx2 && tx2 < w) {
        xs.push_back(tx2);
      }
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end()); // remove duplicate els
  for (int i = 0; i < N; ++i) {
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int main() {
  ifstream ifs("../testset/counting_domain/test3.txt");
  ifs >> W >> H >> N;
  for (int i = 0; i < N; ++i) {
    int x1;
    ifs >> x1;
    X1[i] = x1 - 1;
  }
  for (int i = 0; i < N; ++i) {
    int x2;
    ifs >> x2;
    X2[i] = x2 - 1;
  }
  for (int i = 0; i < N; ++i) {
    int y1;
    ifs >> y1;
    Y1[i] = y1 - 1;
  }
  for (int i = 0; i < N; ++i) {
    int y2;
    ifs >> y2;
    Y2[i] = y2 - 1;
  }
  W = compress(X1, X2, W);
  H = compress(Y1, Y2, H);

  memset(field, 0, sizeof(field));
  for (int i = 0; i < N; ++i) {
    for (int y = Y1[i]; y <= Y2[i]; ++y) {
      for (int x = X1[i]; x <= X2[i]; ++x) {
        field[y][x] = true;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%d", field[i][j]);
    }
    printf("\n");
  }

  int ans = 0;
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (field[y][x])
        continue;
      ++ans;
      field[y][x] = true;
      queue<pii> q;
      q.push(pii(x, y));
      while (!q.empty()) {
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int tx = sx + dx[i];
          int ty = sy + dy[i];
          if (0 <= tx && tx < W && 0 <= ty && ty < H && !field[ty][tx]) {
            q.push(pii(tx, ty));
            field[ty][tx] = true;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
}