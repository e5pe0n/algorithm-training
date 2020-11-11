#include <fstream>
#include <stdio.h>

#define M 1'000'000'007
#define MAX_n 15
#define MAX_m 15

using namespace std;

int n, m, k;
bool color[MAX_n][MAX_m];
int dp[2][1 << MAX_m];

int main() {
  ifstream ifs("../testset/paving_it_with_dominos/test2.txt");
  ifs >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int u, v;
    ifs >> u >> v;
    color[u - 1][v - 1] = true;
  }
  int *crt = dp[0];
  int *nxt = dp[1];
  crt[0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      for (int used = 0; used < 1 << m; ++used) {
        if ((used >> j & 1) || color[i][j]) {
          nxt[used] = crt[used & ~(1 << j)];
        } else {
          int res = 0;
          if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
            res += crt[used | 1 << (j + 1)];
          }
          if (i + 1 < n && !color[i + 1][j]) {
            res += crt[used | 1 << j];
          }
          nxt[used] = res % M;
        }
      }
      // printf("crt=");
      // for (int used = 0; used < 1 << m; ++used) {
      //   printf("%d%c", crt[used], used == (1 << m) - 1 ? '\n' : ' ');
      // }
      // printf("nxt=");
      // for (int used = 0; used < 1 << m; ++used) {
      //   printf("%d%c", nxt[used], used == (1 << m) - 1 ? '\n' : ' ');
      // }
      // printf("\n");
      swap(crt, nxt);
    }
  }
  printf("%d\n", crt[0]);
}