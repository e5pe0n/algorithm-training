#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<vector<int>> V;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    V.emplace_back(vector<int>{a, b});
  }
  sort(V.begin(), V.end());
  ll cnt = 0;
  int res = 0;
  for (auto &v : V) {
    cnt += v[1];
    if (cnt >= K) {
      printf("%d\n", v[0]);
      return 0;
    }
  }
}