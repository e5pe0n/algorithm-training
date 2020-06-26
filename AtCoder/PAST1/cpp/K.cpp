#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Input {
  int N;
  vector<int> P;
  int Q;
  vector<pair<int, int>> C;
};

void solve(int N, vector<int> &P, int Q, vector<pair<int, int>> &C) {
  for (auto c : C) {
    int p = P[c.first - 1];
    while (p != -1 && p != c.second) {
      p = P[p - 1];
    }
    if (p == c.second) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}

int main() {
  map<string, Input> cases{
      {"case1",
       Input{
           7,
           {-1, 1, 1, 2, 2, 3, 3},
           6,
           {{7, 1}, {4, 1}, {2, 3}, {5, 1}, {5, 2}, {2, 5}},
       }},
      {"case2", Input{20,
                      {4, 11, 12, -1, 1, 13, 13, 4, 6, 20, 1, 1, 20, 10, 8, 8, 20, 10, 18, 1},
                      20,
                      {{18, 14}, {11, 3}, {2, 13}, {13, 11}, {10, 15}, {9, 5},  {17, 11},
                       {18, 10}, {1, 16}, {9, 4},  {19, 6},  {5, 10},  {17, 8}, {15, 8},
                       {5, 16},  {6, 20}, {3, 19}, {10, 12}, {5, 13},  {18, 1}}}}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v.N, v.P, v.Q, v.C);
    printf("\n");
  }
}

// [case1]
// Yes
// Yes
// No
// Yes
// Yes
// No

// [case2]
// No
// No
// No
// No
// No
// No
// No
// Yes
// No
// Yes
// No
// No
// No
// Yes
// No
// Yes
// No
// No
// No
// Yes
