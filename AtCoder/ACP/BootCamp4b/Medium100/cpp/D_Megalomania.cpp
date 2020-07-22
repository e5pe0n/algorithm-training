#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 200'000

typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> V;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    V.emplace_back(vector<int>{b, a});
  }
  sort(V.begin(), V.end());
  ll s = 0;
  for (auto &v : V) {
    s += v[1];
    if (s > v[0]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}