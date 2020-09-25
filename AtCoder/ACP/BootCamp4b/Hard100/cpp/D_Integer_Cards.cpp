#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  map<ll, ll> Counter;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++Counter[a];
  }
  for (int i = 0; i < M; ++i) {
    int b, c;
    cin >> b >> c;
    Counter[c] += b;
  }
  vector<vector<ll>> V;
  for (auto pair : Counter) {
    V.push_back(vector<ll>{pair.first, pair.second});
  }
  sort(V.begin(), V.end());
  int cnt = 0;
  ll ans = 0;
  for (int i = V.size() - 1; i >= 0; --i) {
    ans += V[i][0] * min(V[i][1], (ll)(N - cnt));
    cnt += V[i][1];
    if (cnt >= N) {
      break;
    }
  }
  printf("%lld\n", ans);
}