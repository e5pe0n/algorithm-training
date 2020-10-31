#include <algorithm>
#include <fstream>
#include <stdio.h>

#define INF 1'000'000'000
#define MAX_N 1000
#define MAX_ML 10000
#define MAX_MD 10000

using namespace std;

int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];
int d[MAX_N];

int main() {
  ifstream ifs("../testset/layout/test1.txt");
  ifs >> N >> ML >> MD;
  for (int i = 0; i < ML; ++i) {
    int al, bl, dl;
    ifs >> al >> bl >> dl;
    AL[i] = al - 1;
    BL[i] = bl - 1;
    DL[i] = dl;
  }
  for (int i = 0; i < MD; ++i) {
    int ad, bd, dd;
    ifs >> ad >> bd >> dd;
    AD[i] = ad - 1;
    BD[i] = bd - 1;
    DD[i] = dd;
  }
  fill(d, d + N, INF);
  d[0] = 0;

  // Bellman-Ford
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i + 1 < N; ++i) {
      if (d[i + 1] < INF) {
        d[i] = min(d[i], d[i + 1]);
      }
    }
    for (int i = 0; i < ML; ++i) {
      if (d[AL[i]] < INF) {
        d[BL[i]] = min(d[BL[i]], d[AL[i]] + DL[i]);
      }
    }
    for (int i = 0; i < MD; ++i) {
      if (d[BD[i]] < INF) {
        d[AD[i]] = min(d[AD[i]], d[BD[i]] - DD[i]);
      }
    }
  }

  int res = d[N - 1];
  if (d[0] < 0) {
    res = -1;
  } else if (res == INF) {
    res = -2;
  }
  printf("%d\n", res);
}