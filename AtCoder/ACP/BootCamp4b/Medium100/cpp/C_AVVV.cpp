#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int _n = n / 2;
  unordered_map<int, int> M0;
  unordered_map<int, int> M1;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    if (i % 2 == 0) {
      ++M0[v];
    } else {
      ++M1[v];
    }
  }
  vector<vector<int>> V0;
  for (auto &m : M0) {
    V0.push_back(vector<int>{m.second, m.first});
  }
  vector<vector<int>> V1;
  for (auto &m : M1) {
    V1.push_back(vector<int>{m.second, m.first});
  }
  sort(V0.begin(), V0.end());
  sort(V1.begin(), V1.end());
  int N0 = V0.size();
  int N1 = V1.size();
  if (V0[N0 - 1][1] == V1[N1 - 1][1]) {
    if (N0 == 1 && N1 == 1) {
      printf("%d\n", _n);
    } else if (V0[N0 - 1][0] == V1[N1 - 1][0]) {
      if (V0[N0 - 2][0] <= V1[N1 - 2][0]) {
        printf("%d\n", abs(V0[N0 - 1][0] - _n) + abs(V1[N1 - 2][0] - _n));
      } else {
        printf("%d\n", abs(V0[N0 - 2][0] - _n) + abs(V1[N1 - 1][0] - _n));
      }
    } else {
      if (V0[N0 - 1][0] < V1[N1 - 1][0]) {
        printf("%d\n", abs(V0[N0 - 2][0] - _n) + abs(V1[N1 - 1][0] - _n));
      } else {
        printf("%d\n", abs(V0[N0 - 1][0] - _n) + abs(V1[N1 - 2][0] - _n));
      }
    }
  } else {
    printf("%d\n", abs(V0[N0 - 1][0] - _n) + abs(V1[N1 - 1][0] - _n));
  }
}