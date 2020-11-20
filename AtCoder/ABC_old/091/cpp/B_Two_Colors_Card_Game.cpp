#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> B;
  unordered_map<string, int> R;
  int N, M;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    B[s] += 1;
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    string s;
    cin >> s;
    R[s] += 1;
  }
  int res = 0;
  for (auto &b : B) {
    int r_cnt = 0;
    if (R.count(b.first)) {
      r_cnt = R[b.first];
    }
    res = max(res, (int)(b.second - r_cnt));
  }
  printf("%d\n", res);
}