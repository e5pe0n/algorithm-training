#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

int extracted[5];
bool skip[6];

void off_line_minimum(int m, int n, vector<vector<int>> K) {
  int K_size = K.size();
  int cnt = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < K_size - 1; ++j) {
      if (skip[j]) {
        continue;
      }
      for (int k = 0; k < K[j].size(); ++k) {
        if (K[j][k] == i) {
          extracted[j] = i;
          skip[j] = true;
          if (++cnt == m)
            return;
          break;
        }
      }
      if (skip[j]) {
        int l = j + 1;
        while (skip[l]) {
          ++l;
        }
        for (int k = 0; k < K[j].size(); ++k) {
          if (K[j][k] != i) {
            K[l].push_back(K[j][k]);
          }
        }
        K[j] = vector<int>(0);
        break;
      }
    }
  }
}

int main() {
  vector<vector<int>> K{{8, 2}, {4, 5}, {}, {3, 6, 9}, {1, 0}, {7}};
  off_line_minimum(5, 9, K);

  for (int i = 0; i < 5; ++i) {
    printf("%d, ", extracted[i]); // 2, 4, 5, 3, 0,
  }
  printf("\n");
}