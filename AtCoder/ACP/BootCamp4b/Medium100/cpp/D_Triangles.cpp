#include <algorithm>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <vector>

#define MAX_N 2000

using namespace std;

int L[MAX_N];
bool B[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  memset(B, 1, 3);
  int res = 0;
  do {
    vector<int> V;
    for (int i = 0; i < N; ++i) {
      if (B[i]) {
        V.push_back(L[i]);
      }
    }
    if (V[0] < V[1] + V[2] && V[1] < V[2] + V[0] && V[2] < V[0] + V[1]) {
      ++res;
    }
  } while (prev_permutation(B, B + N));
  printf("%d\n", res);
}