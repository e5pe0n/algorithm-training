#include <bits/stdc++.h>
#define MAX_M 200'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M + 2];

void solve() {
  if (M == 0) {
    printf("1\n");
    return;
  }
  A[0] = 0;
  A[M + 1] = N + 1;
  sort(A, A + M + 2);
  vector<ll> V;
  for (int i = 1; i < M + 2; ++i) {
    ll d = A[i] - A[i - 1] - 1;
    if (d) {
      V.push_back(d);
    }
  }
  ll res = 0;
  if (V.size()) {
    ll k = *min_element(V.begin(), V.end());
    for (auto v : V) {
      res += (v + k - 1) / k;
      // printf("v=%lld, k=%lld, %lld\n", v, k, (v + k - 1) / k);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    cin >> A[i];
  }
  solve();
}