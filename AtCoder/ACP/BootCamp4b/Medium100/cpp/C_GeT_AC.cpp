#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_N 100'000
#define MAX_Q 100'000

using namespace std;

int R[MAX_Q];

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> V;
  for (int i = 0; i < N - 1; ++i) {
    if (S.substr(i, 2) == "AC") {
      V.push_back(i);
    }
  }
  for (int i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r;
    if (V.size() > 0) {
      --l;
      --r;
      auto low = lower_bound(V.begin(), V.end(), l);
      auto up = upper_bound(V.begin(), V.end(), r - 1) - 1;
      R[i] = (int)(up - V.begin()) - (int)(low - V.begin()) + 1;
    } else {
      R[i] = 0;
    }
  }
  for (int i = 0; i < Q; ++i) {
    printf("%d\n", R[i]);
  }
}