#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#define INF 1'000'000'000

using namespace std;

struct Input {
  int N;
  int M;
  vector<string> R;
};

int dfs(vector<pair<string, int>> &X, int N, int M, vector<bool> &selected, int cost, int j) {
  if (j >= N) {
    return cost;
  }

  int min_cost = INF;
  for (int i = 0; i < M; ++i) {
    if (X[i].first[j] == 'Y') {
      vector<bool> _selected(selected);
      int _cost = cost;
      if (!selected[i]) {
        _cost += X[i].second;
        _selected[i] = true;
      }
      _cost = dfs(X, N, M, _selected, _cost, j + 1);
      min_cost = min(min_cost, _cost);
    }
  }
  return min_cost;
}

void solve(int N, int M, vector<string> &R) {
  vector<pair<string, int>> X;
  for (auto r : R) {
    X.emplace_back(make_pair<string, int>(r.substr(0, N), stoi(r.substr(N + 1, r.size()))));
  }
  vector<bool> selected(M, false);
  int cost = dfs(X, N, M, selected, 0, 0);
  if (cost >= INF) {
    printf("-1\n");
  } else {
    printf("%d\n", cost);
  }
}

int main() {
  map<string, Input> cases{
      {"case1", Input{3, 4, vector<string>{"YYY 100", "YYN 20", "YNY 10", "NYY 25"}}},
      {"case2", Input{5, 4, vector<string>{"YNNNN 10", "NYNNN 10", "NNYNN 10", "NNNYN 10"}}},
      {"case3", Input{10, 14,
                      vector<string>{
                          "YNNYNNNYYN 774472905",
                          "YYNNNNNYYY 75967554",
                          "NNNNNNNNNN 829389188",
                          "NNNNYYNNNN 157257407",
                          "YNNYNNYNNN 233604939",
                          "NYYNNNNNYY 40099278",
                          "NNNNYNNNNN 599672237",
                          "NNNYNNNNYY 511018842",
                          "NNNYNNYNYN 883299962",
                          "NNNNNNNNYN 883093359",
                          "NNNNNYNYNY 54742561",
                          "NYNNYYYNNY 386272705",
                          "NNNNYYNNNN 565075143",
                          "NNYNYNNNYN 123300589",
                      }}}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v.N, v.M, v.R);
    printf("\n");
  }
}
