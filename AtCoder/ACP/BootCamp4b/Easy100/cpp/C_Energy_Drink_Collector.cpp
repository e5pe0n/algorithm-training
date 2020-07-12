#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> V;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    V.emplace_back(vector<int>{a, b});
  }
  sort(V.begin(), V.end());
  ll res = 0;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    res += (ll)V[i][0] * V[i][1];
    cnt += V[i][1];
    if (cnt > M) {
      res -= V[i][0] * (cnt - M);
      break;
    }
  }
  printf("%lld\n", res);
}