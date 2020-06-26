#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Input {
  int N;
  int M;
  vector<pair<int, int>> R;
};

double dfs(vector<pair<int, int>> &R, int N, int M, vector<bool> &selected, int helper_idx, int j) {
  if (j >= 5) {
    int mass = 0;
    int magic = 0;
    for (int i = 0; i < N; ++i) {
      if (selected[i]) {
        mass += R[i].first;
        magic += R[i].second;
      }
    }
    if (helper_idx >= N) {
      mass += R[helper_idx].first;
      magic += R[helper_idx].second;
    }
    return magic / mass;
  }

  double max_power = 0.0;
  for (int i = 0; i < N + M; ++i) {
    if (!selected[i]) {
      if (i >= N) {
        for (int k = N; k < N + M; ++k) {
          selected[k] = true;
        }
        helper_idx = i;
      } else {
        selected[i] = true;
      }
      max_power = max(max_power, dfs(R, N, M, selected, helper_idx, j + 1));
      if (i >= N) {
        for (int k = N; k < N + M; ++k) {
          selected[k] = false;
        }
        helper_idx = i;
      } else {
        selected[i] = false;
      }
    }
  }
  return max_power;
}

void solve(int N, int M, vector<pair<int, int>> &R) {
  vector<bool> selected(N + M, false);
  double res = dfs(R, N, M, selected, 0, 0);
  printf("%.13f\n", res);
}

int main() {
  map<string, Input> cases{
      {"case1",
       Input{
           6,
           2,
           {{10, 30}, {20, 60}, {10, 10}, {30, 100}, {50, 140}, {40, 120}, {10, 3}, {30, 1}},
       }},
      {"case2", Input{6, 2, {{1, 20}, {1, 3}, {32, 100}, {1, 1}, {1, 2}, {2, 5}, {10, 100}, {96, 874}}}}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v.N, v.M, v.R);
    printf("\n");
  }
}

// [case1]
// 3.0000000000000

// [case2]
// 9.0000000000000
