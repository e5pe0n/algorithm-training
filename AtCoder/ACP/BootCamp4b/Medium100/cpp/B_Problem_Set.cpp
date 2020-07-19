#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<int, int> D;
  for (int i = 0; i < N; ++i) {
    int d;
    cin >> d;
    ++D[d];
  }
  int M;
  cin >> M;
  bool flg = true;
  for (int i = 0; i < M; ++i) {
    int t;
    cin >> t;
    if (D[t] <= 0) {
      flg = false;
    } else {
      --D[t];
    }
  }
  if (flg) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}