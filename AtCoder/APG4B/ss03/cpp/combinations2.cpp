// with replacement
#include <stdio.h>
#include <vector>

using namespace std;

void dfs(const vector<int> &v, vector<int> t, vector<vector<int>> &ret, int n, int k, int i, int j) {
  if (i >= k) {
    ret.push_back(t);
    return;
  }
  for (int l = j; l < n; ++l) {
    vector<int> _t(t);
    _t.push_back(v[l]);
    dfs(v, _t, ret, n, k, i + 1, l);
  }
}

vector<vector<int>> combinations_with_replacement(const vector<int> &v, int n, int k) {
  vector<vector<int>> ret;
  for (int i = 0; i < n; ++i) {
    dfs(v, vector<int>{v[i]}, ret, n, k, 1, i);
  }
  return ret;
}

int main() {
  vector<int> v{2, 1, 3};
  vector<vector<int>> comb_r = combinations_with_replacement(v, v.size(), 2);
  for (auto &c : comb_r) {
    for (auto &_c : c) {
      printf("%d ", _c);
    }
    printf("\n");
  }
  // 2 2
  // 2 1
  // 2 3
  // 1 1
  // 1 3
  // 3 3
}