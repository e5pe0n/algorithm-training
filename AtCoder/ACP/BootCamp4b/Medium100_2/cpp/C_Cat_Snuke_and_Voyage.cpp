#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
using namespace std;
typedef long long ll;

int N, M;
int A[MAX_N], B[MAX_M];
int a[MAX_N];

void solve() {
  vector<int> V;
  for (int i = 0; i < M; ++i) {
    if (A[i] == 0) {
      V.push_back(B[i]);
    }
    a[A[i]] = B[i];
  }
  for (auto v : V) {
    if (a[v] == N - 1) {
      puts("POSSIBLE");
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}