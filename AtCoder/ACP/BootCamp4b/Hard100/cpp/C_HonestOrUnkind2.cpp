#include <bitset>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 15

using namespace std;

vector<vector<int>> A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
      int x, y;
      cin >> x >> y;
      A[i].push_back(vector<int>{x - 1, y});
    }
  }
  int ans = 0;
  for (int i = 1; i < (1 << N); ++i) {
    bitset<MAX_N> B(i);
    int cnt = 0;
    bool possible = true;
    for (int j = 0; j < N; ++j) {
      if (B.test(j)) {
        ++cnt;
        for (auto v : A[j]) {
          if (B.test(v[0]) != v[1]) {
            possible = false;
            break;
          }
        }
      }
    }
    if (possible) {
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans);
}