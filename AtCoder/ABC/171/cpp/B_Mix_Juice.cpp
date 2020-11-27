#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 1000
using namespace std;

int N, K;
int p[MAX_N];

void solve() {
  sort(p, p + N);
  int res = 0;
  for (int i = 0; i < K; ++i) {
    res += p[i];
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  solve();
}