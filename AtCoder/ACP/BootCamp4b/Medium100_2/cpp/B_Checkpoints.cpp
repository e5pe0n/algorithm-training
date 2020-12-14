#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 50
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_N], B[MAX_N];
ll C[MAX_M], D[MAX_M];

void solve() {
  for (int i = 0; i < N; ++i) {
    ll min_d = INF;
    ll res;
    for (int j = 0; j < M; ++j) {
      ll d = abs(A[i] - C[j]) + abs(B[i] - D[j]);
      if (d < min_d) {
        min_d = d;
        res = j + 1;
      }
    }
    printf("%lld\n", res);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> C[i] >> D[i];
  }
  solve();
}