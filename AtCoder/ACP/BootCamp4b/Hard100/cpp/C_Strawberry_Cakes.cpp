#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_H 300
#define MAX_W 300

using namespace std;

string S[MAX_H]{};
int A[MAX_H][MAX_W]{};

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  map<int, set<int>> M{};
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        M[j].insert(i);
      }
    }
  }
  M[W].insert(0);
  int n = 0;
  int left = 0;
  auto right_it = ++M.begin();
  for (auto it = M.begin(); it != M.end(); ++it) {
    if (it == --M.end()) {
      break;
    }
    set<int> s = it->second;
    s.insert(H);
    auto bottom_it = ++s.begin();
    ++n;
    for (int i = 0; i < H; ++i) {
      if (i == *bottom_it) {
        ++n;
        ++bottom_it;
      }
      for (int j = left; j < right_it->first; ++j) {
        A[i][j] = n;
      }
    }
    left = right_it->first;
    ++right_it;
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}