#include <iostream>
#include <stdio.h>
#include <unordered_set>

#define MAX_N 200'001

using namespace std;

bool B[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  unordered_set<int> S;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      S.insert(b);
    } else if (b == N) {
      B[a] = true;
    }
  }
  for (auto &s : S) {
    if (B[s]) {
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");
}