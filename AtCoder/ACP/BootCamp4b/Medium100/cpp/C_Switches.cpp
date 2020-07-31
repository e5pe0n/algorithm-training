#include <bitset>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_M 10

using namespace std;

vector<int> V[MAX_M];
int P[MAX_M];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int k;
    cin >> k;
    vector<int> v;
    for (int j = 0; j < k; ++j) {
      int s;
      cin >> s;
      v.push_back(s - 1);
    }
    V[i] = v;
  }
  for (int i = 0; i < M; ++i) {
    cin >> P[i];
  }
  int res = 0;
  for (int i = 0; i < 1 << N; ++i) {
    bitset<MAX_M> B(i);
    bool flg = true;
    for (int j = 0; j < M; ++j) {
      int cnt = 0;
      for (auto &s : V[j]) {
        if (B.test(s)) {
          ++cnt;
        }
      }
      if (cnt % 2 != P[j]) {
        flg = false;
      }
    }
    res += flg;
  }
  printf("%d\n", res);
}