#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll A[MAX_N];
ll B[MAX_M], C[MAX_M];

void solve() {
  sort(A, A + N);
  vector<pll> V;
  for (int i = 0; i < M; ++i) {
    V.push_back({C[i], B[i]});
  }
  sort(V.begin(), V.end());
  int idx = V.size() - 1;
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    if (idx < 0) {
      res += A[i];
    } else {
      res += max(A[i], V[idx].first);
      --V[idx].second;
      if (V[idx].second == 0) {
        --idx;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i] >> C[i];
  }
  solve();
}