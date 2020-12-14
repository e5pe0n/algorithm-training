#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N, K;
int A[MAX_N];

void solve() {
  map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  vector<int> V;
  for (auto p : cnt) {
    V.push_back(p.second);
  }
  sort(V.begin(), V.end());
  int res = 0;
  int i = 0;
  int k = cnt.size();
  while (k-- > K) {
    res += V[i++];
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}