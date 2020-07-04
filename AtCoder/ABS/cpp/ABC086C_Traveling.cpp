// probably logic is right but out of allowed memory
#include <iostream>
#include <stdio.h>

#define MAX_N 100001

using namespace std;

int X[MAX_N];
int Y[MAX_N];
int T[MAX_N];

bool C[2][MAX_N][MAX_N]{}; // memory over

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i] >> X[i] >> Y[i];
  }

  C[0][0][0] = true;
  int i = 0;
  for (int t = 1; t <= T[N - 1]; ++t) {
    int _t = t % 2;
    for (int j = 0; j <= N; ++j) {
      for (int k = 0; k <= N; ++k) {
        int _tt = (t - 1) % 2;
        C[_t][j][k] = (j - 1 >= 0 && C[_tt][j - 1][k]) || (j + 1 <= N && C[_tt][j + 1][k]) ||
                      (k - 1 >= 0 && C[_tt][j][k - 1]) || (k + 1 <= N && C[_tt][j][k + 1]);
      }
    }
    if (t == T[i]) {
      if (!C[_t][X[i]][Y[i]]) {
        printf("No\n");
        return 0;
      }
      ++i;
    }
  }
  printf("Yes\n");
}