#include <bits/stdc++.h>
#define MAX_N 200'000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll sum[MAX_N + 1];

void solve() {
  for (int i = 0; i < N; ++i) {
    sum[i + 1] = sum[i] + A[i];
  }
  ll res = INF;
  for (int i = 1; i < N; ++i) {
    res = min(res, abs(sum[N] - sum[i] - sum[i]));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}