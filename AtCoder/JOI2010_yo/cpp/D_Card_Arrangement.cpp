#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

#define MAX_N 10
#define MAX_K 4

using namespace std;

bool B[MAX_N]{};
int C[MAX_N];
int D[MAX_K];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  memset(B, 1, K);
  unordered_set<int> S;
  do {
    int j = 0;
    for (int i = 0; i < N; ++i) {
      if (B[i]) {
        D[j++] = i;
      }
    }
    do {
      string s;
      for (int i = 0; i < K; ++i) {
        s += to_string(C[D[i]]);
      }
      S.insert(stoi(s));
    } while (next_permutation(D, D + K));
  } while (prev_permutation(B, B + N));
  printf("%d\n", (int)S.size());
}