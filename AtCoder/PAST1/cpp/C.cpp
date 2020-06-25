#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &V) {
  sort(V.begin(), V.end());
  printf("%d\n", V[3]);
}

int main() {
  map<string, vector<int>> cases{{"case1", vector<int>{4, 18, 25, 20, 9, 13}},
                                 {"case2", vector<int>{95, 96, 07, 98, 99, 100}},
                                 {"case3", vector<int>{19, 92, 3, 35, 78, 1}}};

  for (auto &[k, v] : cases) {
    printf("%s\n", k.c_str());
    solve(v);
    printf("\n");
  }
}